#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};




// Corresponds to kinematics__srv__Kinematics_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Kinematics_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub target: geometry_msgs::msg::PoseStamped,

}



impl Default for Kinematics_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::Kinematics_Request::default())
  }
}

impl rosidl_runtime_rs::Message for Kinematics_Request {
  type RmwMsg = super::srv::rmw::Kinematics_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        target: geometry_msgs::msg::PoseStamped::into_rmw_message(std::borrow::Cow::Owned(msg.target)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        target: geometry_msgs::msg::PoseStamped::into_rmw_message(std::borrow::Cow::Borrowed(&msg.target)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      target: geometry_msgs::msg::PoseStamped::from_rmw_message(msg.target),
    }
  }
}


// Corresponds to kinematics__srv__Kinematics_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Kinematics_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub solution: sensor_msgs::msg::JointState,

}



impl Default for Kinematics_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::Kinematics_Response::default())
  }
}

impl rosidl_runtime_rs::Message for Kinematics_Response {
  type RmwMsg = super::srv::rmw::Kinematics_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
        solution: sensor_msgs::msg::JointState::into_rmw_message(std::borrow::Cow::Owned(msg.solution)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
        solution: sensor_msgs::msg::JointState::into_rmw_message(std::borrow::Cow::Borrowed(&msg.solution)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
      solution: sensor_msgs::msg::JointState::from_rmw_message(msg.solution),
    }
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


