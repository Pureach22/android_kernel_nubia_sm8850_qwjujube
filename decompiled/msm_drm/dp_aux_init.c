__int64 __fastcall dp_aux_init(__int64 result, _DWORD *a2)
{
  __int64 v2; // x19
  void (__fastcall *v3)(_QWORD); // x9
  __int64 v4; // x0
  void (*v5)(void); // x8
  __int64 (*v6)(void); // x8

  if ( result && a2 )
  {
    if ( (*(_BYTE *)(result + 1807) & 1) == 0 )
    {
      a2[1] = 0;
      v2 = result;
      a2[7] = 0;
      a2[13] = 0;
      a2[19] = 0;
      a2[25] = 0;
      a2[31] = 0;
      a2[37] = 0;
      a2[43] = 0;
      a2[49] = 0;
      a2[55] = 0;
      v3 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(result + 120) + 64LL);
      v4 = *(_QWORD *)(result + 120);
      if ( *((_DWORD *)v3 - 1) != -22640554 )
        __break(0x8229u);
      v3(v4);
      v5 = *(void (**)(void))(*(_QWORD *)(v2 + 120) + 40LL);
      if ( *((_DWORD *)v5 - 1) != -1040530234 )
        __break(0x8228u);
      v5();
      v6 = *(__int64 (**)(void))(*(_QWORD *)(v2 + 120) + 48LL);
      if ( *((_DWORD *)v6 - 1) != 497885965 )
        __break(0x8228u);
      result = v6();
      *(_DWORD *)(v2 + 1832) = 0;
      *(_DWORD *)(v2 + 1820) = 0;
      *(_BYTE *)(v2 + 1807) = 1;
    }
  }
  else
  {
    if ( result )
      ipc_log_string(*(_QWORD *)(result + 16), "[e][%-4d]invalid input\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    _ReadStatusReg(SP_EL0);
    return printk(&unk_275B6D, "dp_aux_init");
  }
  return result;
}
