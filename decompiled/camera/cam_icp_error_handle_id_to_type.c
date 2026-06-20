const char *__fastcall cam_icp_error_handle_id_to_type(int a1)
{
  const char *result; // x0

  if ( a1 > 999 )
  {
    if ( a1 > 1001 )
    {
      if ( a1 == 1002 )
      {
        return "HFI_QUEUE_EMPTY";
      }
      else if ( a1 == 1003 )
      {
        return "HFI_QUEUE_FULL";
      }
      else
      {
        return nullptr;
      }
    }
    else if ( a1 == 1000 )
    {
      return "HFI_ERR_COMMAND_SIZE";
    }
    else
    {
      return "HFI_ERR_MESSAGE_SIZE";
    }
  }
  else
  {
    result = "SUCCESS";
    switch ( a1 )
    {
      case 0:
        return result;
      case 1:
        result = "EFAILED";
        break;
      case 2:
        result = "ENOMEMORY";
        break;
      case 3:
        result = "EBADSTATE";
        break;
      case 4:
        result = "EBADPARM";
        break;
      case 5:
        result = "EBADITEM";
        break;
      case 6:
        result = "EINVALIDFORMAT";
        break;
      case 7:
        result = "EUNSUPPORTED";
        break;
      case 8:
        result = "EOUTOFBOUND";
        break;
      case 9:
        result = "ETIMEDOUT";
        break;
      case 10:
        result = "EABORTED";
        break;
      case 11:
        result = "EHWVIOLATION";
        break;
      case 12:
        result = "ECDMERROR";
        break;
      default:
        return nullptr;
    }
  }
  return result;
}
