__int64 __fastcall msm_vidc_get_buffers(__int64 a1, unsigned int a2, __int64 a3)
{
  __int64 result; // x0

  result = 0;
  switch ( a2 )
  {
    case 1u:
      result = a1 + 2504;
      break;
    case 2u:
      result = a1 + 2544;
      break;
    case 3u:
      result = a1 + 2624;
      break;
    case 4u:
      result = a1 + 2664;
      break;
    case 5u:
      result = a1 + 2584;
      break;
    case 6u:
      return result;
    case 7u:
      result = a1 + 2704;
      break;
    case 8u:
      result = a1 + 2744;
      break;
    case 9u:
      result = a1 + 2784;
      break;
    case 0xAu:
      result = a1 + 2824;
      break;
    case 0xBu:
      result = a1 + 2864;
      break;
    case 0xCu:
      result = a1 + 2904;
      break;
    case 0xDu:
      result = a1 + 2944;
      break;
    case 0xEu:
      result = a1 + 2984;
      break;
    case 0xFu:
      result = a1 + 3024;
      break;
    default:
      if ( a1 && (msm_vidc_debug & 1) != 0 )
      {
        printk(&unk_9780D, "err ", a1 + 340, a3, a2);
        result = 0;
      }
      else
      {
        result = 0;
      }
      break;
  }
  return result;
}
