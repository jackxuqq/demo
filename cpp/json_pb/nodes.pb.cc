// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: nodes.proto

#include "nodes.pb.h"

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

namespace kim {
PROTOBUF_CONSTEXPR addr_info::addr_info(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.bind_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_.gate_bind_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_.port_)*/0u
  , /*decltype(_impl_.gate_port_)*/0u
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct addr_infoDefaultTypeInternal {
  PROTOBUF_CONSTEXPR addr_infoDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~addr_infoDefaultTypeInternal() {}
  union {
    addr_info _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 addr_infoDefaultTypeInternal _addr_info_default_instance_;
PROTOBUF_CONSTEXPR node_info::node_info(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.name_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_.node_type_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_.conf_path_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_.work_path_)*/{&::_pbi::fixed_address_empty_string, ::_pbi::ConstantInitialized{}}
  , /*decltype(_impl_.addr_info_)*/nullptr
  , /*decltype(_impl_.worker_cnt_)*/0
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct node_infoDefaultTypeInternal {
  PROTOBUF_CONSTEXPR node_infoDefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~node_infoDefaultTypeInternal() {}
  union {
    node_info _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 node_infoDefaultTypeInternal _node_info_default_instance_;
}  // namespace kim
static ::_pb::Metadata file_level_metadata_nodes_2eproto[2];
static constexpr ::_pb::EnumDescriptor const** file_level_enum_descriptors_nodes_2eproto = nullptr;
static constexpr ::_pb::ServiceDescriptor const** file_level_service_descriptors_nodes_2eproto = nullptr;

const uint32_t TableStruct_nodes_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::kim::addr_info, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::kim::addr_info, _impl_.bind_),
  PROTOBUF_FIELD_OFFSET(::kim::addr_info, _impl_.port_),
  PROTOBUF_FIELD_OFFSET(::kim::addr_info, _impl_.gate_bind_),
  PROTOBUF_FIELD_OFFSET(::kim::addr_info, _impl_.gate_port_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::kim::node_info, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::kim::node_info, _impl_.name_),
  PROTOBUF_FIELD_OFFSET(::kim::node_info, _impl_.addr_info_),
  PROTOBUF_FIELD_OFFSET(::kim::node_info, _impl_.node_type_),
  PROTOBUF_FIELD_OFFSET(::kim::node_info, _impl_.conf_path_),
  PROTOBUF_FIELD_OFFSET(::kim::node_info, _impl_.work_path_),
  PROTOBUF_FIELD_OFFSET(::kim::node_info, _impl_.worker_cnt_),
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::kim::addr_info)},
  { 10, -1, -1, sizeof(::kim::node_info)},
};

static const ::_pb::Message* const file_default_instances[] = {
  &::kim::_addr_info_default_instance_._instance,
  &::kim::_node_info_default_instance_._instance,
};

const char descriptor_table_protodef_nodes_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\013nodes.proto\022\003kim\"M\n\taddr_info\022\014\n\004bind\030"
  "\001 \001(\t\022\014\n\004port\030\002 \001(\r\022\021\n\tgate_bind\030\003 \001(\t\022\021"
  "\n\tgate_port\030\004 \001(\r\"\211\001\n\tnode_info\022\014\n\004name\030"
  "\001 \001(\t\022!\n\taddr_info\030\002 \001(\0132\016.kim.addr_info"
  "\022\021\n\tnode_type\030\003 \001(\t\022\021\n\tconf_path\030\004 \001(\t\022\021"
  "\n\twork_path\030\005 \001(\t\022\022\n\nworker_cnt\030\006 \001(\005b\006p"
  "roto3"
  ;
static ::_pbi::once_flag descriptor_table_nodes_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_nodes_2eproto = {
    false, false, 245, descriptor_table_protodef_nodes_2eproto,
    "nodes.proto",
    &descriptor_table_nodes_2eproto_once, nullptr, 0, 2,
    schemas, file_default_instances, TableStruct_nodes_2eproto::offsets,
    file_level_metadata_nodes_2eproto, file_level_enum_descriptors_nodes_2eproto,
    file_level_service_descriptors_nodes_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_nodes_2eproto_getter() {
  return &descriptor_table_nodes_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_nodes_2eproto(&descriptor_table_nodes_2eproto);
namespace kim {

// ===================================================================

class addr_info::_Internal {
 public:
};

addr_info::addr_info(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:kim.addr_info)
}
addr_info::addr_info(const addr_info& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  addr_info* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.bind_){}
    , decltype(_impl_.gate_bind_){}
    , decltype(_impl_.port_){}
    , decltype(_impl_.gate_port_){}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  _impl_.bind_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.bind_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_bind().empty()) {
    _this->_impl_.bind_.Set(from._internal_bind(), 
      _this->GetArenaForAllocation());
  }
  _impl_.gate_bind_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.gate_bind_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_gate_bind().empty()) {
    _this->_impl_.gate_bind_.Set(from._internal_gate_bind(), 
      _this->GetArenaForAllocation());
  }
  ::memcpy(&_impl_.port_, &from._impl_.port_,
    static_cast<size_t>(reinterpret_cast<char*>(&_impl_.gate_port_) -
    reinterpret_cast<char*>(&_impl_.port_)) + sizeof(_impl_.gate_port_));
  // @@protoc_insertion_point(copy_constructor:kim.addr_info)
}

inline void addr_info::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.bind_){}
    , decltype(_impl_.gate_bind_){}
    , decltype(_impl_.port_){0u}
    , decltype(_impl_.gate_port_){0u}
    , /*decltype(_impl_._cached_size_)*/{}
  };
  _impl_.bind_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.bind_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  _impl_.gate_bind_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.gate_bind_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
}

addr_info::~addr_info() {
  // @@protoc_insertion_point(destructor:kim.addr_info)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void addr_info::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.bind_.Destroy();
  _impl_.gate_bind_.Destroy();
}

void addr_info::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void addr_info::Clear() {
// @@protoc_insertion_point(message_clear_start:kim.addr_info)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.bind_.ClearToEmpty();
  _impl_.gate_bind_.ClearToEmpty();
  ::memset(&_impl_.port_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&_impl_.gate_port_) -
      reinterpret_cast<char*>(&_impl_.port_)) + sizeof(_impl_.gate_port_));
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* addr_info::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // string bind = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          auto str = _internal_mutable_bind();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "kim.addr_info.bind"));
        } else
          goto handle_unusual;
        continue;
      // uint32 port = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 16)) {
          _impl_.port_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // string gate_bind = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 26)) {
          auto str = _internal_mutable_gate_bind();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "kim.addr_info.gate_bind"));
        } else
          goto handle_unusual;
        continue;
      // uint32 gate_port = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 32)) {
          _impl_.gate_port_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
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

uint8_t* addr_info::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:kim.addr_info)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // string bind = 1;
  if (!this->_internal_bind().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_bind().data(), static_cast<int>(this->_internal_bind().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "kim.addr_info.bind");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_bind(), target);
  }

  // uint32 port = 2;
  if (this->_internal_port() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteUInt32ToArray(2, this->_internal_port(), target);
  }

  // string gate_bind = 3;
  if (!this->_internal_gate_bind().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_gate_bind().data(), static_cast<int>(this->_internal_gate_bind().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "kim.addr_info.gate_bind");
    target = stream->WriteStringMaybeAliased(
        3, this->_internal_gate_bind(), target);
  }

  // uint32 gate_port = 4;
  if (this->_internal_gate_port() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteUInt32ToArray(4, this->_internal_gate_port(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:kim.addr_info)
  return target;
}

size_t addr_info::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:kim.addr_info)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string bind = 1;
  if (!this->_internal_bind().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_bind());
  }

  // string gate_bind = 3;
  if (!this->_internal_gate_bind().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_gate_bind());
  }

  // uint32 port = 2;
  if (this->_internal_port() != 0) {
    total_size += ::_pbi::WireFormatLite::UInt32SizePlusOne(this->_internal_port());
  }

  // uint32 gate_port = 4;
  if (this->_internal_gate_port() != 0) {
    total_size += ::_pbi::WireFormatLite::UInt32SizePlusOne(this->_internal_gate_port());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData addr_info::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    addr_info::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*addr_info::GetClassData() const { return &_class_data_; }


void addr_info::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<addr_info*>(&to_msg);
  auto& from = static_cast<const addr_info&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:kim.addr_info)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_bind().empty()) {
    _this->_internal_set_bind(from._internal_bind());
  }
  if (!from._internal_gate_bind().empty()) {
    _this->_internal_set_gate_bind(from._internal_gate_bind());
  }
  if (from._internal_port() != 0) {
    _this->_internal_set_port(from._internal_port());
  }
  if (from._internal_gate_port() != 0) {
    _this->_internal_set_gate_port(from._internal_gate_port());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void addr_info::CopyFrom(const addr_info& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:kim.addr_info)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool addr_info::IsInitialized() const {
  return true;
}

void addr_info::InternalSwap(addr_info* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.bind_, lhs_arena,
      &other->_impl_.bind_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.gate_bind_, lhs_arena,
      &other->_impl_.gate_bind_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(addr_info, _impl_.gate_port_)
      + sizeof(addr_info::_impl_.gate_port_)
      - PROTOBUF_FIELD_OFFSET(addr_info, _impl_.port_)>(
          reinterpret_cast<char*>(&_impl_.port_),
          reinterpret_cast<char*>(&other->_impl_.port_));
}

::PROTOBUF_NAMESPACE_ID::Metadata addr_info::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_nodes_2eproto_getter, &descriptor_table_nodes_2eproto_once,
      file_level_metadata_nodes_2eproto[0]);
}

// ===================================================================

class node_info::_Internal {
 public:
  static const ::kim::addr_info& addr_info(const node_info* msg);
};

const ::kim::addr_info&
node_info::_Internal::addr_info(const node_info* msg) {
  return *msg->_impl_.addr_info_;
}
node_info::node_info(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:kim.node_info)
}
node_info::node_info(const node_info& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  node_info* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.name_){}
    , decltype(_impl_.node_type_){}
    , decltype(_impl_.conf_path_){}
    , decltype(_impl_.work_path_){}
    , decltype(_impl_.addr_info_){nullptr}
    , decltype(_impl_.worker_cnt_){}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  _impl_.name_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.name_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_name().empty()) {
    _this->_impl_.name_.Set(from._internal_name(), 
      _this->GetArenaForAllocation());
  }
  _impl_.node_type_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.node_type_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_node_type().empty()) {
    _this->_impl_.node_type_.Set(from._internal_node_type(), 
      _this->GetArenaForAllocation());
  }
  _impl_.conf_path_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.conf_path_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_conf_path().empty()) {
    _this->_impl_.conf_path_.Set(from._internal_conf_path(), 
      _this->GetArenaForAllocation());
  }
  _impl_.work_path_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.work_path_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (!from._internal_work_path().empty()) {
    _this->_impl_.work_path_.Set(from._internal_work_path(), 
      _this->GetArenaForAllocation());
  }
  if (from._internal_has_addr_info()) {
    _this->_impl_.addr_info_ = new ::kim::addr_info(*from._impl_.addr_info_);
  }
  _this->_impl_.worker_cnt_ = from._impl_.worker_cnt_;
  // @@protoc_insertion_point(copy_constructor:kim.node_info)
}

inline void node_info::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.name_){}
    , decltype(_impl_.node_type_){}
    , decltype(_impl_.conf_path_){}
    , decltype(_impl_.work_path_){}
    , decltype(_impl_.addr_info_){nullptr}
    , decltype(_impl_.worker_cnt_){0}
    , /*decltype(_impl_._cached_size_)*/{}
  };
  _impl_.name_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.name_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  _impl_.node_type_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.node_type_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  _impl_.conf_path_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.conf_path_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  _impl_.work_path_.InitDefault();
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
    _impl_.work_path_.Set("", GetArenaForAllocation());
  #endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
}

node_info::~node_info() {
  // @@protoc_insertion_point(destructor:kim.node_info)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void node_info::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.name_.Destroy();
  _impl_.node_type_.Destroy();
  _impl_.conf_path_.Destroy();
  _impl_.work_path_.Destroy();
  if (this != internal_default_instance()) delete _impl_.addr_info_;
}

void node_info::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void node_info::Clear() {
// @@protoc_insertion_point(message_clear_start:kim.node_info)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.name_.ClearToEmpty();
  _impl_.node_type_.ClearToEmpty();
  _impl_.conf_path_.ClearToEmpty();
  _impl_.work_path_.ClearToEmpty();
  if (GetArenaForAllocation() == nullptr && _impl_.addr_info_ != nullptr) {
    delete _impl_.addr_info_;
  }
  _impl_.addr_info_ = nullptr;
  _impl_.worker_cnt_ = 0;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* node_info::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // string name = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 10)) {
          auto str = _internal_mutable_name();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "kim.node_info.name"));
        } else
          goto handle_unusual;
        continue;
      // .kim.addr_info addr_info = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 18)) {
          ptr = ctx->ParseMessage(_internal_mutable_addr_info(), ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // string node_type = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 26)) {
          auto str = _internal_mutable_node_type();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "kim.node_info.node_type"));
        } else
          goto handle_unusual;
        continue;
      // string conf_path = 4;
      case 4:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 34)) {
          auto str = _internal_mutable_conf_path();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "kim.node_info.conf_path"));
        } else
          goto handle_unusual;
        continue;
      // string work_path = 5;
      case 5:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 42)) {
          auto str = _internal_mutable_work_path();
          ptr = ::_pbi::InlineGreedyStringParser(str, ptr, ctx);
          CHK_(ptr);
          CHK_(::_pbi::VerifyUTF8(str, "kim.node_info.work_path"));
        } else
          goto handle_unusual;
        continue;
      // int32 worker_cnt = 6;
      case 6:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 48)) {
          _impl_.worker_cnt_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint32(&ptr);
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

uint8_t* node_info::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:kim.node_info)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // string name = 1;
  if (!this->_internal_name().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_name().data(), static_cast<int>(this->_internal_name().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "kim.node_info.name");
    target = stream->WriteStringMaybeAliased(
        1, this->_internal_name(), target);
  }

  // .kim.addr_info addr_info = 2;
  if (this->_internal_has_addr_info()) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(2, _Internal::addr_info(this),
        _Internal::addr_info(this).GetCachedSize(), target, stream);
  }

  // string node_type = 3;
  if (!this->_internal_node_type().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_node_type().data(), static_cast<int>(this->_internal_node_type().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "kim.node_info.node_type");
    target = stream->WriteStringMaybeAliased(
        3, this->_internal_node_type(), target);
  }

  // string conf_path = 4;
  if (!this->_internal_conf_path().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_conf_path().data(), static_cast<int>(this->_internal_conf_path().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "kim.node_info.conf_path");
    target = stream->WriteStringMaybeAliased(
        4, this->_internal_conf_path(), target);
  }

  // string work_path = 5;
  if (!this->_internal_work_path().empty()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->_internal_work_path().data(), static_cast<int>(this->_internal_work_path().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "kim.node_info.work_path");
    target = stream->WriteStringMaybeAliased(
        5, this->_internal_work_path(), target);
  }

  // int32 worker_cnt = 6;
  if (this->_internal_worker_cnt() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteInt32ToArray(6, this->_internal_worker_cnt(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:kim.node_info)
  return target;
}

size_t node_info::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:kim.node_info)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string name = 1;
  if (!this->_internal_name().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_name());
  }

  // string node_type = 3;
  if (!this->_internal_node_type().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_node_type());
  }

  // string conf_path = 4;
  if (!this->_internal_conf_path().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_conf_path());
  }

  // string work_path = 5;
  if (!this->_internal_work_path().empty()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->_internal_work_path());
  }

  // .kim.addr_info addr_info = 2;
  if (this->_internal_has_addr_info()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *_impl_.addr_info_);
  }

  // int32 worker_cnt = 6;
  if (this->_internal_worker_cnt() != 0) {
    total_size += ::_pbi::WireFormatLite::Int32SizePlusOne(this->_internal_worker_cnt());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData node_info::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    node_info::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*node_info::GetClassData() const { return &_class_data_; }


void node_info::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<node_info*>(&to_msg);
  auto& from = static_cast<const node_info&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:kim.node_info)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  if (!from._internal_name().empty()) {
    _this->_internal_set_name(from._internal_name());
  }
  if (!from._internal_node_type().empty()) {
    _this->_internal_set_node_type(from._internal_node_type());
  }
  if (!from._internal_conf_path().empty()) {
    _this->_internal_set_conf_path(from._internal_conf_path());
  }
  if (!from._internal_work_path().empty()) {
    _this->_internal_set_work_path(from._internal_work_path());
  }
  if (from._internal_has_addr_info()) {
    _this->_internal_mutable_addr_info()->::kim::addr_info::MergeFrom(
        from._internal_addr_info());
  }
  if (from._internal_worker_cnt() != 0) {
    _this->_internal_set_worker_cnt(from._internal_worker_cnt());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void node_info::CopyFrom(const node_info& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:kim.node_info)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool node_info::IsInitialized() const {
  return true;
}

void node_info::InternalSwap(node_info* other) {
  using std::swap;
  auto* lhs_arena = GetArenaForAllocation();
  auto* rhs_arena = other->GetArenaForAllocation();
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.name_, lhs_arena,
      &other->_impl_.name_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.node_type_, lhs_arena,
      &other->_impl_.node_type_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.conf_path_, lhs_arena,
      &other->_impl_.conf_path_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::InternalSwap(
      &_impl_.work_path_, lhs_arena,
      &other->_impl_.work_path_, rhs_arena
  );
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(node_info, _impl_.worker_cnt_)
      + sizeof(node_info::_impl_.worker_cnt_)
      - PROTOBUF_FIELD_OFFSET(node_info, _impl_.addr_info_)>(
          reinterpret_cast<char*>(&_impl_.addr_info_),
          reinterpret_cast<char*>(&other->_impl_.addr_info_));
}

::PROTOBUF_NAMESPACE_ID::Metadata node_info::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_nodes_2eproto_getter, &descriptor_table_nodes_2eproto_once,
      file_level_metadata_nodes_2eproto[1]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace kim
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::kim::addr_info*
Arena::CreateMaybeMessage< ::kim::addr_info >(Arena* arena) {
  return Arena::CreateMessageInternal< ::kim::addr_info >(arena);
}
template<> PROTOBUF_NOINLINE ::kim::node_info*
Arena::CreateMaybeMessage< ::kim::node_info >(Arena* arena) {
  return Arena::CreateMessageInternal< ::kim::node_info >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
