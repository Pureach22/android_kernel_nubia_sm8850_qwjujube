__int64 __fastcall target_if_cp_stats_inc_wake_lock_stats(__int64 result, _DWORD *a2, _DWORD *a3)
{
  switch ( (int)result )
  {
    case -1:
      goto LABEL_20;
    case 0:
      a3 = a2 + 14;
      goto LABEL_20;
    case 2:
      a3 = a2 + 11;
      goto LABEL_20;
    case 3:
      a3 = a2 + 26;
      goto LABEL_20;
    case 4:
      a3 = a2 + 21;
      goto LABEL_20;
    case 15:
      a3 = a2 + 25;
      goto LABEL_20;
    case 16:
      a3 = a2 + 20;
      goto LABEL_20;
    case 29:
      a3 = a2 + 12;
      goto LABEL_20;
    case 30:
      a3 = a2 + 10;
      goto LABEL_20;
    case 33:
      a3 = a2 + 13;
      goto LABEL_20;
    case 35:
      a3 = a2 + 22;
      goto LABEL_20;
    case 36:
      a3 = a2 + 23;
      goto LABEL_20;
    case 37:
      a3 = a2 + 24;
      goto LABEL_20;
    case 38:
      a3 = a2 + 27;
      goto LABEL_20;
    case 41:
      a3 = a2 + 15;
      goto LABEL_20;
    case 46:
      a3 = a2 + 18;
      goto LABEL_20;
    case 47:
      a3 = a2 + 19;
      goto LABEL_20;
    case 64:
      a3 = a2 + 16;
      goto LABEL_20;
    case 68:
      a3 = a2 + 17;
LABEL_20:
      ++*a3;
      break;
    default:
      return result;
  }
  return result;
}
