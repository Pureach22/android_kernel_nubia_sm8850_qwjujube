__int64 __fastcall power_off_iris2(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x8
  void (__fastcall *v3)(_QWORD); // x9
  void (__fastcall *v4)(_QWORD); // x8
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v6; // x8

  if ( *(_BYTE *)(result + 72) == 1 && *(_BYTE *)(*(_QWORD *)(result + 2208) + 329LL) == 1 )
  {
    v1 = result;
    if ( (*(_BYTE *)(result + 20) & 8) == 0 )
    {
      disable_irq_nosync(**(unsigned int **)(result + 2168));
      result = v1;
    }
    v2 = *(_QWORD *)(result + 2512);
    *(_DWORD *)(result + 20) = 0;
    if ( v2 )
    {
      v3 = *(void (__fastcall **)(_QWORD))(v2 + 24);
      if ( !v3 )
        goto LABEL_11;
      if ( *((_DWORD *)v3 - 1) != -1303076162 )
        __break(0x8229u);
      v3(v1);
      v2 = *(_QWORD *)(v1 + 2512);
      result = v1;
      if ( v2 )
      {
LABEL_11:
        v4 = *(void (__fastcall **)(_QWORD))(v2 + 16);
        if ( v4 )
        {
          if ( *((_DWORD *)v4 - 1) != -1303076162 )
            __break(0x8228u);
          v4(v1);
          result = v1;
        }
      }
    }
    if ( (unsigned int)_unvote_buses(result) && (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      printk(&unk_8B198, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), "warn");
    }
    *(_BYTE *)(v1 + 72) = 0;
    v6 = _ReadStatusReg(SP_EL0);
    return printk(&unk_8E8F9, *(unsigned int *)(v6 + 1800), *(unsigned int *)(v6 + 1804), &unk_8DA84);
  }
  return result;
}
