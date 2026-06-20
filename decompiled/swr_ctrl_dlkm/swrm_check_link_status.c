__int64 __fastcall swrm_check_link_status(__int64 result, char a2)
{
  __int64 v2; // x19
  int v4; // w21
  const char *v6; // x3

  if ( *(int *)(result + 9128) >= 17104898 )
  {
    v2 = result;
    v4 = -100;
    while ( 1 )
    {
      result = swr_master_read(v2, (unsigned int)((*(_DWORD *)(v2 + 9056) << 12) + 16484));
      if ( (result & 1) == (a2 & 1) )
        break;
      usleep_range_state(500, 510, 2);
      if ( __CFADD__(v4++, 1) )
      {
        result = __ratelimit(&swrm_check_link_status__rs, "swrm_check_link_status");
        if ( (_DWORD)result )
        {
          if ( (a2 & 1) != 0 )
            v6 = "connected";
          else
            v6 = "disconnected";
          return dev_err(*(_QWORD *)(v2 + 8512), "%s: link status not %s\n", "swrm_check_link_status", v6);
        }
        return result;
      }
    }
  }
  return result;
}
