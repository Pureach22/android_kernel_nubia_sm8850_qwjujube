__int64 __fastcall _disable_subcaches(__int64 result, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x8
  __int64 v5; // x19
  unsigned __int64 v6; // x11
  unsigned __int64 v7; // x24
  unsigned __int64 StatusReg; // x28

  if ( (msm_cvp_syscache_disable & 1) == 0 )
  {
    v4 = *(_QWORD *)(result + 2208);
    v5 = result;
    if ( *(_BYTE *)(v4 + 192) == 1 )
    {
      v6 = *(_QWORD *)(v4 + 200);
      v7 = v6 + 24LL * (unsigned int)(*(_DWORD *)(v4 + 208) - 1);
      if ( v7 >= v6 )
      {
        StatusReg = _ReadStatusReg(SP_EL0);
        do
        {
          if ( *(_BYTE *)(v7 + 8) == 1 )
          {
            if ( (msm_cvp_debug & 0x100) != 0 && !msm_cvp_debug_out )
              printk(&unk_939C9, "core", *(_QWORD *)v7, a4);
            result = llcc_slice_deactivate(*(_QWORD *)(v7 + 16));
            if ( (_DWORD)result && (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
              result = printk(
                         &unk_8E8C3,
                         *(unsigned int *)(StatusReg + 1800),
                         *(unsigned int *)(StatusReg + 1804),
                         "warn");
            *(_BYTE *)(v7 + 8) = 0;
            v4 = *(_QWORD *)(v5 + 2208);
          }
          v7 -= 24LL;
        }
        while ( v7 >= *(_QWORD *)(v4 + 200) );
      }
    }
  }
  return result;
}
