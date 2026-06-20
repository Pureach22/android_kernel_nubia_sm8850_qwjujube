__int64 __fastcall dp_mon_filter_reset_rx_pktlog_cbf(__int64 result)
{
  __int64 v1; // x8
  __int64 v2; // x8
  __int64 v3; // x8
  __int64 (*v4)(void); // x8

  v1 = *(_QWORD *)(result + 8);
  if ( v1 )
  {
    v2 = *(_QWORD *)(v1 + 20112);
    if ( v2 )
    {
      v3 = *(_QWORD *)(v2 + 416);
      if ( v3 )
      {
        v4 = *(__int64 (**)(void))(v3 + 640);
        if ( v4 )
        {
          if ( *((_DWORD *)v4 - 1) != -1557217772 )
            __break(0x8228u);
          return v4();
        }
      }
    }
  }
  return result;
}
