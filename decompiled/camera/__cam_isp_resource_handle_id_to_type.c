const char *__fastcall _cam_isp_resource_handle_id_to_type(int a1, unsigned int a2)
{
  switch ( a1 )
  {
    case 65555:
      return (const char *)_cam_isp_ife_sfe_resource_handle_id_to_type(a2);
    case 65552:
      if ( a2 - 1 > 0xE )
        return "Invalid_Resource_Type";
      else
        return off_4517A8[a2 - 1];
    case 65538:
      return (const char *)_cam_isp_ife_sfe_resource_handle_id_to_type(a2);
    default:
      return "INVALID_DEV_TYPE";
  }
}
