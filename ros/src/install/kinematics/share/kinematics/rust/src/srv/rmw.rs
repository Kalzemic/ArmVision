#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



#[link(name = "kinematics__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__kinematics__srv__Kinematics_Request() -> *const std::ffi::c_void;
}

#[link(name = "kinematics__rosidl_generator_c")]
extern "C" {
    fn kinematics__srv__Kinematics_Request__init(msg: *mut Kinematics_Request) -> bool;
    fn kinematics__srv__Kinematics_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Kinematics_Request>, size: usize) -> bool;
    fn kinematics__srv__Kinematics_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Kinematics_Request>);
    fn kinematics__srv__Kinematics_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Kinematics_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<Kinematics_Request>) -> bool;
}

// Corresponds to kinematics__srv__Kinematics_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Kinematics_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub target: geometry_msgs::msg::rmw::PoseStamped,

}



impl Default for Kinematics_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !kinematics__srv__Kinematics_Request__init(&mut msg as *mut _) {
        panic!("Call to kinematics__srv__Kinematics_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Kinematics_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { kinematics__srv__Kinematics_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { kinematics__srv__Kinematics_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { kinematics__srv__Kinematics_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Kinematics_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Kinematics_Request where Self: Sized {
  const TYPE_NAME: &'static str = "kinematics/srv/Kinematics_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__kinematics__srv__Kinematics_Request() }
  }
}


#[link(name = "kinematics__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__kinematics__srv__Kinematics_Response() -> *const std::ffi::c_void;
}

#[link(name = "kinematics__rosidl_generator_c")]
extern "C" {
    fn kinematics__srv__Kinematics_Response__init(msg: *mut Kinematics_Response) -> bool;
    fn kinematics__srv__Kinematics_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Kinematics_Response>, size: usize) -> bool;
    fn kinematics__srv__Kinematics_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Kinematics_Response>);
    fn kinematics__srv__Kinematics_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Kinematics_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<Kinematics_Response>) -> bool;
}

// Corresponds to kinematics__srv__Kinematics_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Kinematics_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub solution: sensor_msgs::msg::rmw::JointState,

}



impl Default for Kinematics_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !kinematics__srv__Kinematics_Response__init(&mut msg as *mut _) {
        panic!("Call to kinematics__srv__Kinematics_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Kinematics_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { kinematics__srv__Kinematics_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { kinematics__srv__Kinematics_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { kinematics__srv__Kinematics_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Kinematics_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Kinematics_Response where Self: Sized {
  const TYPE_NAME: &'static str = "kinematics/srv/Kinematics_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__kinematics__srv__Kinematics_Response() }
  }
}






#[link(name = "kinematics__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__kinematics__srv__Kinematics() -> *const std::ffi::c_void;
}

// Corresponds to kinematics__srv__Kinematics
#[allow(missing_docs, non_camel_case_types)]
pub struct Kinematics;

impl rosidl_runtime_rs::Service for Kinematics {
    type Request = Kinematics_Request;
    type Response = Kinematics_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__kinematics__srv__Kinematics() }
    }
}


