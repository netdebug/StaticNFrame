// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: demonhunter.proto

#ifndef PROTOBUF_demonhunter_2eproto__INCLUDED
#define PROTOBUF_demonhunter_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2005000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace proto {
namespace message {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_demonhunter_2eproto();
void protobuf_AssignDesc_demonhunter_2eproto();
void protobuf_ShutdownFile_demonhunter_2eproto();

class DH_CS_GetReword;
class DH_SC_AckStatus;
class DH_SC_GetDHInfo;

// ===================================================================

class DH_CS_GetReword : public ::google::protobuf::Message {
 public:
  DH_CS_GetReword();
  virtual ~DH_CS_GetReword();

  DH_CS_GetReword(const DH_CS_GetReword& from);

  inline DH_CS_GetReword& operator=(const DH_CS_GetReword& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const DH_CS_GetReword& default_instance();

  void Swap(DH_CS_GetReword* other);

  // implements Message ----------------------------------------------

  DH_CS_GetReword* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const DH_CS_GetReword& from);
  void MergeFrom(const DH_CS_GetReword& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional uint32 rewordid = 1;
  inline bool has_rewordid() const;
  inline void clear_rewordid();
  static const int kRewordidFieldNumber = 1;
  inline ::google::protobuf::uint32 rewordid() const;
  inline void set_rewordid(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:proto.message.DH_CS_GetReword)
 private:
  inline void set_has_rewordid();
  inline void clear_has_rewordid();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 rewordid_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_demonhunter_2eproto();
  friend void protobuf_AssignDesc_demonhunter_2eproto();
  friend void protobuf_ShutdownFile_demonhunter_2eproto();

  void InitAsDefaultInstance();
  static DH_CS_GetReword* default_instance_;
};
// -------------------------------------------------------------------

class DH_SC_AckStatus : public ::google::protobuf::Message {
 public:
  DH_SC_AckStatus();
  virtual ~DH_SC_AckStatus();

  DH_SC_AckStatus(const DH_SC_AckStatus& from);

  inline DH_SC_AckStatus& operator=(const DH_SC_AckStatus& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const DH_SC_AckStatus& default_instance();

  void Swap(DH_SC_AckStatus* other);

  // implements Message ----------------------------------------------

  DH_SC_AckStatus* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const DH_SC_AckStatus& from);
  void MergeFrom(const DH_SC_AckStatus& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional uint32 result = 1;
  inline bool has_result() const;
  inline void clear_result();
  static const int kResultFieldNumber = 1;
  inline ::google::protobuf::uint32 result() const;
  inline void set_result(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:proto.message.DH_SC_AckStatus)
 private:
  inline void set_has_result();
  inline void clear_has_result();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 result_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_demonhunter_2eproto();
  friend void protobuf_AssignDesc_demonhunter_2eproto();
  friend void protobuf_ShutdownFile_demonhunter_2eproto();

  void InitAsDefaultInstance();
  static DH_SC_AckStatus* default_instance_;
};
// -------------------------------------------------------------------

class DH_SC_GetDHInfo : public ::google::protobuf::Message {
 public:
  DH_SC_GetDHInfo();
  virtual ~DH_SC_GetDHInfo();

  DH_SC_GetDHInfo(const DH_SC_GetDHInfo& from);

  inline DH_SC_GetDHInfo& operator=(const DH_SC_GetDHInfo& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const DH_SC_GetDHInfo& default_instance();

  void Swap(DH_SC_GetDHInfo* other);

  // implements Message ----------------------------------------------

  DH_SC_GetDHInfo* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const DH_SC_GetDHInfo& from);
  void MergeFrom(const DH_SC_GetDHInfo& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional uint32 dhlev = 1;
  inline bool has_dhlev() const;
  inline void clear_dhlev();
  static const int kDhlevFieldNumber = 1;
  inline ::google::protobuf::uint32 dhlev() const;
  inline void set_dhlev(::google::protobuf::uint32 value);

  // optional int32 dhexp = 2;
  inline bool has_dhexp() const;
  inline void clear_dhexp();
  static const int kDhexpFieldNumber = 2;
  inline ::google::protobuf::int32 dhexp() const;
  inline void set_dhexp(::google::protobuf::int32 value);

  // optional int32 dhcounts = 3;
  inline bool has_dhcounts() const;
  inline void clear_dhcounts();
  static const int kDhcountsFieldNumber = 3;
  inline ::google::protobuf::int32 dhcounts() const;
  inline void set_dhcounts(::google::protobuf::int32 value);

  // optional int32 dhbuyCounts = 4;
  inline bool has_dhbuycounts() const;
  inline void clear_dhbuycounts();
  static const int kDhbuyCountsFieldNumber = 4;
  inline ::google::protobuf::int32 dhbuycounts() const;
  inline void set_dhbuycounts(::google::protobuf::int32 value);

  // optional uint32 dhcanup = 5;
  inline bool has_dhcanup() const;
  inline void clear_dhcanup();
  static const int kDhcanupFieldNumber = 5;
  inline ::google::protobuf::uint32 dhcanup() const;
  inline void set_dhcanup(::google::protobuf::uint32 value);

  // repeated uint32 rewodidlist = 6;
  inline int rewodidlist_size() const;
  inline void clear_rewodidlist();
  static const int kRewodidlistFieldNumber = 6;
  inline ::google::protobuf::uint32 rewodidlist(int index) const;
  inline void set_rewodidlist(int index, ::google::protobuf::uint32 value);
  inline void add_rewodidlist(::google::protobuf::uint32 value);
  inline const ::google::protobuf::RepeatedField< ::google::protobuf::uint32 >&
      rewodidlist() const;
  inline ::google::protobuf::RepeatedField< ::google::protobuf::uint32 >*
      mutable_rewodidlist();

  // @@protoc_insertion_point(class_scope:proto.message.DH_SC_GetDHInfo)
 private:
  inline void set_has_dhlev();
  inline void clear_has_dhlev();
  inline void set_has_dhexp();
  inline void clear_has_dhexp();
  inline void set_has_dhcounts();
  inline void clear_has_dhcounts();
  inline void set_has_dhbuycounts();
  inline void clear_has_dhbuycounts();
  inline void set_has_dhcanup();
  inline void clear_has_dhcanup();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 dhlev_;
  ::google::protobuf::int32 dhexp_;
  ::google::protobuf::int32 dhcounts_;
  ::google::protobuf::int32 dhbuycounts_;
  ::google::protobuf::RepeatedField< ::google::protobuf::uint32 > rewodidlist_;
  ::google::protobuf::uint32 dhcanup_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(6 + 31) / 32];

  friend void  protobuf_AddDesc_demonhunter_2eproto();
  friend void protobuf_AssignDesc_demonhunter_2eproto();
  friend void protobuf_ShutdownFile_demonhunter_2eproto();

  void InitAsDefaultInstance();
  static DH_SC_GetDHInfo* default_instance_;
};
// ===================================================================


// ===================================================================

// DH_CS_GetReword

// optional uint32 rewordid = 1;
inline bool DH_CS_GetReword::has_rewordid() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void DH_CS_GetReword::set_has_rewordid() {
  _has_bits_[0] |= 0x00000001u;
}
inline void DH_CS_GetReword::clear_has_rewordid() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void DH_CS_GetReword::clear_rewordid() {
  rewordid_ = 0u;
  clear_has_rewordid();
}
inline ::google::protobuf::uint32 DH_CS_GetReword::rewordid() const {
  return rewordid_;
}
inline void DH_CS_GetReword::set_rewordid(::google::protobuf::uint32 value) {
  set_has_rewordid();
  rewordid_ = value;
}

// -------------------------------------------------------------------

// DH_SC_AckStatus

// optional uint32 result = 1;
inline bool DH_SC_AckStatus::has_result() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void DH_SC_AckStatus::set_has_result() {
  _has_bits_[0] |= 0x00000001u;
}
inline void DH_SC_AckStatus::clear_has_result() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void DH_SC_AckStatus::clear_result() {
  result_ = 0u;
  clear_has_result();
}
inline ::google::protobuf::uint32 DH_SC_AckStatus::result() const {
  return result_;
}
inline void DH_SC_AckStatus::set_result(::google::protobuf::uint32 value) {
  set_has_result();
  result_ = value;
}

// -------------------------------------------------------------------

// DH_SC_GetDHInfo

// optional uint32 dhlev = 1;
inline bool DH_SC_GetDHInfo::has_dhlev() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void DH_SC_GetDHInfo::set_has_dhlev() {
  _has_bits_[0] |= 0x00000001u;
}
inline void DH_SC_GetDHInfo::clear_has_dhlev() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void DH_SC_GetDHInfo::clear_dhlev() {
  dhlev_ = 0u;
  clear_has_dhlev();
}
inline ::google::protobuf::uint32 DH_SC_GetDHInfo::dhlev() const {
  return dhlev_;
}
inline void DH_SC_GetDHInfo::set_dhlev(::google::protobuf::uint32 value) {
  set_has_dhlev();
  dhlev_ = value;
}

// optional int32 dhexp = 2;
inline bool DH_SC_GetDHInfo::has_dhexp() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void DH_SC_GetDHInfo::set_has_dhexp() {
  _has_bits_[0] |= 0x00000002u;
}
inline void DH_SC_GetDHInfo::clear_has_dhexp() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void DH_SC_GetDHInfo::clear_dhexp() {
  dhexp_ = 0;
  clear_has_dhexp();
}
inline ::google::protobuf::int32 DH_SC_GetDHInfo::dhexp() const {
  return dhexp_;
}
inline void DH_SC_GetDHInfo::set_dhexp(::google::protobuf::int32 value) {
  set_has_dhexp();
  dhexp_ = value;
}

// optional int32 dhcounts = 3;
inline bool DH_SC_GetDHInfo::has_dhcounts() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void DH_SC_GetDHInfo::set_has_dhcounts() {
  _has_bits_[0] |= 0x00000004u;
}
inline void DH_SC_GetDHInfo::clear_has_dhcounts() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void DH_SC_GetDHInfo::clear_dhcounts() {
  dhcounts_ = 0;
  clear_has_dhcounts();
}
inline ::google::protobuf::int32 DH_SC_GetDHInfo::dhcounts() const {
  return dhcounts_;
}
inline void DH_SC_GetDHInfo::set_dhcounts(::google::protobuf::int32 value) {
  set_has_dhcounts();
  dhcounts_ = value;
}

// optional int32 dhbuyCounts = 4;
inline bool DH_SC_GetDHInfo::has_dhbuycounts() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void DH_SC_GetDHInfo::set_has_dhbuycounts() {
  _has_bits_[0] |= 0x00000008u;
}
inline void DH_SC_GetDHInfo::clear_has_dhbuycounts() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void DH_SC_GetDHInfo::clear_dhbuycounts() {
  dhbuycounts_ = 0;
  clear_has_dhbuycounts();
}
inline ::google::protobuf::int32 DH_SC_GetDHInfo::dhbuycounts() const {
  return dhbuycounts_;
}
inline void DH_SC_GetDHInfo::set_dhbuycounts(::google::protobuf::int32 value) {
  set_has_dhbuycounts();
  dhbuycounts_ = value;
}

// optional uint32 dhcanup = 5;
inline bool DH_SC_GetDHInfo::has_dhcanup() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void DH_SC_GetDHInfo::set_has_dhcanup() {
  _has_bits_[0] |= 0x00000010u;
}
inline void DH_SC_GetDHInfo::clear_has_dhcanup() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void DH_SC_GetDHInfo::clear_dhcanup() {
  dhcanup_ = 0u;
  clear_has_dhcanup();
}
inline ::google::protobuf::uint32 DH_SC_GetDHInfo::dhcanup() const {
  return dhcanup_;
}
inline void DH_SC_GetDHInfo::set_dhcanup(::google::protobuf::uint32 value) {
  set_has_dhcanup();
  dhcanup_ = value;
}

// repeated uint32 rewodidlist = 6;
inline int DH_SC_GetDHInfo::rewodidlist_size() const {
  return rewodidlist_.size();
}
inline void DH_SC_GetDHInfo::clear_rewodidlist() {
  rewodidlist_.Clear();
}
inline ::google::protobuf::uint32 DH_SC_GetDHInfo::rewodidlist(int index) const {
  return rewodidlist_.Get(index);
}
inline void DH_SC_GetDHInfo::set_rewodidlist(int index, ::google::protobuf::uint32 value) {
  rewodidlist_.Set(index, value);
}
inline void DH_SC_GetDHInfo::add_rewodidlist(::google::protobuf::uint32 value) {
  rewodidlist_.Add(value);
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::uint32 >&
DH_SC_GetDHInfo::rewodidlist() const {
  return rewodidlist_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::uint32 >*
DH_SC_GetDHInfo::mutable_rewodidlist() {
  return &rewodidlist_;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace message
}  // namespace proto

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_demonhunter_2eproto__INCLUDED