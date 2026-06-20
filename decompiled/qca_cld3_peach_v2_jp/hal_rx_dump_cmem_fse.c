__int64 __fastcall hal_rx_dump_cmem_fse(__int64 result, int a2)
{
  __int64 (*v2)(void); // x8
  __int64 v3; // [xsp+C8h] [xbp-8h]

  v3 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 )
  {
    v2 = *(__int64 (**)(void))(*(_QWORD *)(result + 74392) + 1104LL);
    if ( v2 )
    {
      if ( *((_DWORD *)v2 - 1) != -1046383444 )
        __break(0x8228u);
      result = v2();
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
