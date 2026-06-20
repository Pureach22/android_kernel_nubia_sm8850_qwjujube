__int64 __fastcall dsi_ctrl_hs_req_sel(__int64 result, char a2)
{
  __int64 v2; // x19
  __int64 v4; // x0
  __int64 v5; // x8
  _DWORD *v6; // x8

  if ( result )
  {
    v2 = result;
    v4 = mutex_lock(result + 32);
    v5 = *(unsigned int *)(v2 + 1608);
    if ( (unsigned int)v5 >= 3 )
    {
      __break(0x5512u);
      return dsi_ctrl_set_continuous_clk(v4);
    }
    else
    {
      v6 = *(_DWORD **)(v2 + 8 * v5 + 1440);
      if ( v6 )
      {
        if ( *(v6 - 1) != 1642962683 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, _QWORD))v6)(v2 + 96, a2 & 1);
      }
      return mutex_unlock(v2 + 32);
    }
  }
  return result;
}
