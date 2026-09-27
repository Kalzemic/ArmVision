#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



#[link(name = "trajectory__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__trajectory__srv__Trajectory_Request() -> *const std::ffi::c_void;
}

#[link(name = "trajectory__rosidl_generator_c")]
extern "C" {
    fn trajectory__srv__Trajectory_Request__init(msg: *mut Trajectory_Request) -> bool;
    fn trajectory__srv__Trajectory_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Trajectory_Request>, size: usize) -> bool;
    fn trajectory__srv__Trajectory_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Trajectory_Request>);
    fn trajectory__srv__Trajectory_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Trajectory_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<Trajectory_Request>) -> bool;
}

// Corresponds to trajectory__srv__Trajectory_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Trajectory_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub goal: sensor_msgs::msg::rmw::JointState,


    // This member is not documented.
    #[allow(missing_docs)]
    pub duration: builtin_interfaces::msg::rmw::Duration,

}



impl Default for Trajectory_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !trajectory__srv__Trajectory_Request__init(&mut msg as *mut _) {
        panic!("Call to trajectory__srv__Trajectory_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Trajectory_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { trajectory__srv__Trajectory_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { trajectory__srv__Trajectory_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { trajectory__srv__Trajectory_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Trajectory_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Trajectory_Request where Self: Sized {
  const TYPE_NAME: &'static str = "trajectory/srv/Trajectory_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__trajectory__srv__Trajectory_Request() }
  }
}


#[link(name = "trajectory__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__trajectory__srv__Trajectory_Response() -> *const std::ffi::c_void;
}

#[link(name = "trajectory__rosidl_generator_c")]
extern "C" {
    fn trajectory__srv__Trajectory_Response__init(msg: *mut Trajectory_Response) -> bool;
    fn trajectory__srv__Trajectory_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Trajectory_Response>, size: usize) -> bool;
    fn trajectory__srv__Trajectory_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Trajectory_Response>);
    fn trajectory__srv__Trajectory_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Trajectory_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<Trajectory_Response>) -> bool;
}

// Corresponds to trajectory__srv__Trajectory_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Trajectory_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub trajectory: trajectory_msgs::msg::rmw::JointTrajectory,

}



impl Default for Trajectory_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !trajectory__srv__Trajectory_Response__init(&mut msg as *mut _) {
        panic!("Call to trajectory__srv__Trajectory_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Trajectory_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { trajectory__srv__Trajectory_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { trajectory__srv__Trajectory_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { trajectory__srv__Trajectory_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Trajectory_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Trajectory_Response where Self: Sized {
  const TYPE_NAME: &'static str = "trajectory/srv/Trajectory_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__trajectory__srv__Trajectory_Response() }
  }
}






#[link(name = "trajectory__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__trajectory__srv__Trajectory() -> *const std::ffi::c_void;
}

// Corresponds to trajectory__srv__Trajectory
#[allow(missing_docs, non_camel_case_types)]
pub struct Trajectory;

impl rosidl_runtime_rs::Service for Trajectory {
    type Request = Trajectory_Request;
    type Response = Trajectory_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__trajectory__srv__Trajectory() }
    }
}


