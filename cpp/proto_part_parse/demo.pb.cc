// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: demo.proto

#include "demo.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG

namespace _pb = ::PROTOBUF_NAMESPACE_ID;
namespace _pbi = _pb::internal;

PROTOBUF_CONSTEXPR Point::Point(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.x_)*/0
  , /*decltype(_impl_.y_)*/0
  , /*decltype(_impl_.z_)*/0
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct PointDefaultTypeInternal {
  PROTOBUF_CONSTEXPR PointDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~PointDefaultTypeInternal() {}
  union {
    Point _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 PointDefaultTypeInternal _Point_default_instance_;
PROTOBUF_CONSTEXPR Triangle::Triangle(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.p1_)*/nullptr
  , /*decltype(_impl_.p2_)*/nullptr
  , /*decltype(_impl_.p3_)*/nullptr
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct TriangleDefaultTypeInternal {
  PROTOBUF_CONSTEXPR TriangleDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~TriangleDefaultTypeInternal() {}
  union {
    Triangle _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 TriangleDefaultTypeInternal _Triangle_default_instance_;
PROTOBUF_CONSTEXPR ModelData::ModelData(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.planes_)*/{}
  , /*decltype(_impl_.ret_)*/0
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct ModelDataDefaultTypeInternal {
  PROTOBUF_CONSTEXPR ModelDataDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~ModelDataDefaultTypeInternal() {}
  union {
    ModelData _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 ModelDataDefaultTypeInternal _ModelData_default_instance_;
static ::_pb::Metadata file_level_metadata_demo_2eproto[3];
static constexpr ::_pb::EnumDescriptor const** file_level_enum_descriptors_demo_2eproto = nullptr;
static constexpr ::_pb::ServiceDescriptor const** file_level_service_descriptors_demo_2eproto = nullptr;

const uint32_t TableStruct_demo_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::Point, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::Point, _impl_.x_),
  PROTOBUF_FIELD_OFFSET(::Point, _impl_.y_),
  PROTOBUF_FIELD_OFFSET(::Point, _impl_.z_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::Triangle, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::Triangle, _impl_.p1_),
  PROTOBUF_FIELD_OFFSET(::Triangle, _impl_.p2_),
  PROTOBUF_FIELD_OFFSET(::Triangle, _impl_.p3_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::ModelData, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::ModelData, _impl_.ret_),
  PROTOBUF_FIELD_OFFSET(::ModelData, _impl_.planes_),
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::Point)},
  { 9, -1, -1, sizeof(::Triangle)},
  { 18, -1, -1, sizeof(::ModelData)},
};

static const ::_pb::Message* const file_default_instances[] = {
  &::_Point_default_instance_._instance,
  &::_Triangle_default_instance_._instance,
  &::_ModelData_default_instance_._instance,
};

const char descriptor_table_protodef_demo_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\ndemo.proto\"(\n\005Point\022\t\n\001x\030\001 \001(\005\022\t\n\001y\030\002 "
  "\001(\005\022\t\n\001z\030\003 \001(\005\"F\n\010Triangle\022\022\n\002p1\030\001 \001(\0132\006"
  ".Point\022\022\n\002p2\030\002 \001(\0132\006.Point\022\022\n\002p3\030\003 \001(\0132\006"
  ".Point\"3\n\tModelData\022\013\n\003ret\030\001 \001(\005\022\031\n\006plan"
  "es\030\002 \003(\0132\t.Triangleb\006proto3"
  ;
static ::_pbi::once_flag descriptor_table_demo_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_demo_2eproto = {
    false, false, 187, descriptor_table_protodef_demo_2eproto,
    "demo.proto",
    &descriptor_table_demo_2eproto_once, nullptr, 0, 3,
    schemas, file_default_instances, TableStruct_demo_2eproto::offsets,
    file_level_metadata_demo_2eproto, file_level_enum_descriptors_demo_2eproto,
    file_level_service_descriptors_demo_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_demo_2eproto_getter() {
  return &descriptor_table_demo_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_demo_2eproto(&descriptor_table_demo_2eproto);

// ===================================================================

class Point::_Internal {
 public:
};

Point::Point(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:Point)
}
Point::Point(const Point& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  Point* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.x_){}
    , decltype(_impl_.y_){}
    , decltype(_impl_.z_){}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::memcpy(&_impl_.x_, &from._impl_.x_,
    static_cast<size_t>(reinterpret_cast<char*>(&_impl_.z_) -
    reinterpret_cast<char*>(&_impl_.x_)) + sizeof(_impl_.z_));
  // @@protoc_insertion_point(copy_constructor:Point)
}

inline void Point::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.x_){0}
    , decltype(_impl_.y_){0}
    , decltype(_impl_.z_){0}
    , /*decltype(_impl_._cached_size_)*/{}
  };
}

Point::~Point() {
  // @@protoc_insertion_point(destructor:Point)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void Point::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
}

void Point::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void Point::Clear() {
// @@protoc_insertion_point(message_clear_start:Point)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  ::memset(&_impl_.x_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&_impl_.z_) -
      reinterpret_cast<char*>(&_impl_.x_)) + sizeof(_impl_.z_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Point::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // int32 x = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          _impl_.x_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // int32 y = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 16)) {
          _impl_.y_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // int32 z = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 24)) {
          _impl_.z_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* Point::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Point)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // int32 x = 1;
  if (this->_internal_x() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt32ToArray(1, this->_internal_x(), target);
  }

  // int32 y = 2;
  if (this->_internal_y() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt32ToArray(2, this->_internal_y(), target);
  }

  // int32 z = 3;
  if (this->_internal_z() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt32ToArray(3, this->_internal_z(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Point)
  return target;
}

size_t Point::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Point)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // int32 x = 1;
  if (this->_internal_x() != 0) {
    total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_x());
  }

  // int32 y = 2;
  if (this->_internal_y() != 0) {
    total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_y());
  }

  // int32 z = 3;
  if (this->_internal_z() != 0) {
    total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_z());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData Point::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    Point::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*Point::GetClassData() const { return &_class_data_; }


void Point::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<Point*>(&to_msg);
  auto& from = static_cast<const Point&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:Point)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_x() != 0) {
    _this->_internal_set_x(from._internal_x());
  }
  if (from._internal_y() != 0) {
    _this->_internal_set_y(from._internal_y());
  }
  if (from._internal_z() != 0) {
    _this->_internal_set_z(from._internal_z());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Point::CopyFrom(const Point& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Point)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Point::IsInitialized() const {
  return true;
}

void Point::InternalSwap(Point* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(Point, _impl_.z_)
      + sizeof(Point::_impl_.z_)
      - PROTOBUF_FIELD_OFFSET(Point, _impl_.x_)>(
          reinterpret_cast<char*>(&_impl_.x_),
          reinterpret_cast<char*>(&other->_impl_.x_));
}

::PROTOBUF_NAMESPACE_ID::Metadata Point::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_demo_2eproto_getter, &descriptor_table_demo_2eproto_once,
      file_level_metadata_demo_2eproto[0]);
}

// ===================================================================

class Triangle::_Internal {
 public:
  static const ::Point& p1(const Triangle* msg);
  static const ::Point& p2(const Triangle* msg);
  static const ::Point& p3(const Triangle* msg);
};

const ::Point&
Triangle::_Internal::p1(const Triangle* msg) {
  return *msg->_impl_.p1_;
}
const ::Point&
Triangle::_Internal::p2(const Triangle* msg) {
  return *msg->_impl_.p2_;
}
const ::Point&
Triangle::_Internal::p3(const Triangle* msg) {
  return *msg->_impl_.p3_;
}
Triangle::Triangle(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:Triangle)
}
Triangle::Triangle(const Triangle& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  Triangle* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.p1_){nullptr}
    , decltype(_impl_.p2_){nullptr}
    , decltype(_impl_.p3_){nullptr}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  if (from._internal_has_p1()) {
    _this->_impl_.p1_ = new ::Point(*from._impl_.p1_);
  }
  if (from._internal_has_p2()) {
    _this->_impl_.p2_ = new ::Point(*from._impl_.p2_);
  }
  if (from._internal_has_p3()) {
    _this->_impl_.p3_ = new ::Point(*from._impl_.p3_);
  }
  // @@protoc_insertion_point(copy_constructor:Triangle)
}

inline void Triangle::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.p1_){nullptr}
    , decltype(_impl_.p2_){nullptr}
    , decltype(_impl_.p3_){nullptr}
    , /*decltype(_impl_._cached_size_)*/{}
  };
}

Triangle::~Triangle() {
  // @@protoc_insertion_point(destructor:Triangle)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void Triangle::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  if (this != internal_default_instance()) delete _impl_.p1_;
  if (this != internal_default_instance()) delete _impl_.p2_;
  if (this != internal_default_instance()) delete _impl_.p3_;
}

void Triangle::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void Triangle::Clear() {
// @@protoc_insertion_point(message_clear_start:Triangle)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  if (GetArenaForAllocation() == nullptr && _impl_.p1_ != nullptr) {
    delete _impl_.p1_;
  }
  _impl_.p1_ = nullptr;
  if (GetArenaForAllocation() == nullptr && _impl_.p2_ != nullptr) {
    delete _impl_.p2_;
  }
  _impl_.p2_ = nullptr;
  if (GetArenaForAllocation() == nullptr && _impl_.p3_ != nullptr) {
    delete _impl_.p3_;
  }
  _impl_.p3_ = nullptr;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Triangle::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // .Point p1 = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          ptr = ctx->ParseMessage(_internal_mutable_p1(), ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // .Point p2 = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 18)) {
          ptr = ctx->ParseMessage(_internal_mutable_p2(), ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // .Point p3 = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 26)) {
          ptr = ctx->ParseMessage(_internal_mutable_p3(), ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* Triangle::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:Triangle)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // .Point p1 = 1;
  if (this->_internal_has_p1()) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(1, _Internal::p1(this),
        _Internal::p1(this).GetCachedSize(), target, stream);
  }

  // .Point p2 = 2;
  if (this->_internal_has_p2()) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(2, _Internal::p2(this),
        _Internal::p2(this).GetCachedSize(), target, stream);
  }

  // .Point p3 = 3;
  if (this->_internal_has_p3()) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(3, _Internal::p3(this),
        _Internal::p3(this).GetCachedSize(), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:Triangle)
  return target;
}

size_t Triangle::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:Triangle)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // .Point p1 = 1;
  if (this->_internal_has_p1()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *_impl_.p1_);
  }

  // .Point p2 = 2;
  if (this->_internal_has_p2()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *_impl_.p2_);
  }

  // .Point p3 = 3;
  if (this->_internal_has_p3()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *_impl_.p3_);
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData Triangle::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    Triangle::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*Triangle::GetClassData() const { return &_class_data_; }


void Triangle::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<Triangle*>(&to_msg);
  auto& from = static_cast<const Triangle&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:Triangle)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (from._internal_has_p1()) {
    _this->_internal_mutable_p1()->::Point::MergeFrom(
        from._internal_p1());
  }
  if (from._internal_has_p2()) {
    _this->_internal_mutable_p2()->::Point::MergeFrom(
        from._internal_p2());
  }
  if (from._internal_has_p3()) {
    _this->_internal_mutable_p3()->::Point::MergeFrom(
        from._internal_p3());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Triangle::CopyFrom(const Triangle& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:Triangle)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Triangle::IsInitialized() const {
  return true;
}

void Triangle::InternalSwap(Triangle* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(Triangle, _impl_.p3_)
      + sizeof(Triangle::_impl_.p3_)
      - PROTOBUF_FIELD_OFFSET(Triangle, _impl_.p1_)>(
          reinterpret_cast<char*>(&_impl_.p1_),
          reinterpret_cast<char*>(&other->_impl_.p1_));
}

::PROTOBUF_NAMESPACE_ID::Metadata Triangle::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_demo_2eproto_getter, &descriptor_table_demo_2eproto_once,
      file_level_metadata_demo_2eproto[1]);
}

// ===================================================================

class ModelData::_Internal {
 public:
};

ModelData::ModelData(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:ModelData)
}
ModelData::ModelData(const ModelData& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  ModelData* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.planes_){from._impl_.planes_}
    , decltype(_impl_.ret_){}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  _this->_impl_.ret_ = from._impl_.ret_;
  // @@protoc_insertion_point(copy_constructor:ModelData)
}

inline void ModelData::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.planes_){arena}
    , decltype(_impl_.ret_){0}
    , /*decltype(_impl_._cached_size_)*/{}
  };
}

ModelData::~ModelData() {
  // @@protoc_insertion_point(destructor:ModelData)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void ModelData::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.planes_.~RepeatedPtrField();
}

void ModelData::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void ModelData::Clear() {
// @@protoc_insertion_point(message_clear_start:ModelData)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.planes_.Clear();
  _impl_.ret_ = 0;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* ModelData::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // int32 ret = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          _impl_.ret_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // repeated .Triangle planes = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 18)) {
          ptr -= 1;
          do {
            ptr += 1;
            ptr = ctx->ParseMessage(_internal_add_planes(), ptr);
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<18>(ptr));
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* ModelData::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:ModelData)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // int32 ret = 1;
  if (this->_internal_ret() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt32ToArray(1, this->_internal_ret(), target);
  }

  // repeated .Triangle planes = 2;
  for (unsigned i = 0,
      n = static_cast<unsigned>(this->_internal_planes_size()); i < n; i++) {
    const auto& repfield = this->_internal_planes(i);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
        InternalWriteMessage(2, repfield, repfield.GetCachedSize(), target, stream);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:ModelData)
  return target;
}

size_t ModelData::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:ModelData)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated .Triangle planes = 2;
  total_size += 1UL * this->_internal_planes_size();
  for (const auto& msg : this->_impl_.planes_) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(msg);
  }

  // int32 ret = 1;
  if (this->_internal_ret() != 0) {
    total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_ret());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData ModelData::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    ModelData::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*ModelData::GetClassData() const { return &_class_data_; }


void ModelData::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<ModelData*>(&to_msg);
  auto& from = static_cast<const ModelData&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:ModelData)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  _this->_impl_.planes_.MergeFrom(from._impl_.planes_);
  if (from._internal_ret() != 0) {
    _this->_internal_set_ret(from._internal_ret());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void ModelData::CopyFrom(const ModelData& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:ModelData)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ModelData::IsInitialized() const {
  return true;
}

void ModelData::InternalSwap(ModelData* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  _impl_.planes_.InternalSwap(&other->_impl_.planes_);
  swap(_impl_.ret_, other->_impl_.ret_);
}

::PROTOBUF_NAMESPACE_ID::Metadata ModelData::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_demo_2eproto_getter, &descriptor_table_demo_2eproto_once,
      file_level_metadata_demo_2eproto[2]);
}

// @@protoc_insertion_point(namespace_scope)
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::Point*
Arena::CreateMaybeMessage< ::Point >(Arena* arena) {
  return Arena::CreateMessageInternal< ::Point >(arena);
}
template<> PROTOBUF_NOINLINE ::Triangle*
Arena::CreateMaybeMessage< ::Triangle >(Arena* arena) {
  return Arena::CreateMessageInternal< ::Triangle >(arena);
}
template<> PROTOBUF_NOINLINE ::ModelData*
Arena::CreateMaybeMessage< ::ModelData >(Arena* arena) {
  return Arena::CreateMessageInternal< ::ModelData >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
