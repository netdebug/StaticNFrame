#include "NFRandom.hpp"
#include <vector>

static uint32_t g_seed = 0;
static const uint32_t g_nNull = 0;
static const uint32_t g_nOne = 1;
static const uint32_t g_nPar1 = 214013;
static const uint32_t g_nPar2 = 2531011;
static const uint32_t g_nPar3 = 15;
static const uint32_t g_nPar4 = 16;
static const float g_fPar5 = 1.0f / 65535.0f;
static const double g_dPar6 = 1.0 / 4294967295.0;
static const uint32_t g_nPar7 = 0x7fffffff;

inline uint32_t NFGetSeed()
{
#ifdef _WIN32
    __asm _emit 0x0F
    __asm _emit 0x31
#else
    __asm__ __volatile__(".byte 0x0F");
    __asm__ __volatile__(".byte 0x31");
#endif
}

void NFRandomSeed()
{
	g_seed = NFGetSeed();
}

uint32_t NFRandomAUInt()
{
	g_seed = g_nPar1 * g_seed + g_nPar2;
	return (g_seed ^ g_seed >> g_nPar3);
}

uint32_t NFRandomUInt(uint32_t min, uint32_t max)
{
	if (min > max)
	{
		return max;
	}

	return min + NFRandomAUInt() % (max - min + g_nOne);
}

int32_t NFRandomAInt()
{
	return (int32_t)NFRandomUInt(g_nNull, g_nPar7);
}

int32_t NFRandomInt(int32_t min, int32_t max)
{
	if (min > max)
	{
		return max;
	}

	return min + (int32_t)(NFRandomAUInt() % (max - min + g_nOne));
}

float NFRandomFloat(float min, float max)
{
	if (min > max)
	{
		return max;
	}

	g_seed = g_nPar1 * g_seed + g_nPar2;
	return min + (g_seed >> g_nPar4) * g_fPar5 * (max - min);
}

double NFRandomDouble(double min, double max)
{
	if (min > max)
	{
		return max;
	}

	g_seed = g_nPar1 * g_seed + g_nPar2;
	return min + g_seed * g_dPar6 * (max - min);
}

//����ַ���
const char* NFRandomChar(size_t nChar)
{
	if (nChar == 0)
		return 0;
	static std::vector<char> s_aStr;
	s_aStr.resize(nChar + 1);
	for (size_t i = 0; i < nChar; i++)
		s_aStr[i] = (char)NFRandomUInt(1, 0xff);
	s_aStr[nChar] = 0;
	return &s_aStr.front();
}

//���Ӣ��
const char* NFRandomEnglish(size_t nChar)
{
	if (nChar == 0)
		return 0;
	static std::vector<char> s_aStr;
	s_aStr.resize(nChar + 1);
	for (size_t i = 0; i < nChar; i++) {
		if (NFRandomAInt() % 2 == 0)
			s_aStr[i] = (char)NFRandomUInt('A', 'Z');
		else
			s_aStr[i] = (char)NFRandomUInt('a', 'z');
	}
	s_aStr[nChar] = 0;
	return &s_aStr.front();
}