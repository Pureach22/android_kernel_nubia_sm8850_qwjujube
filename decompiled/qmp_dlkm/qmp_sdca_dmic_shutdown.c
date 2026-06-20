void __fastcall qmp_sdca_dmic_shutdown(__int64 a1, __int64 a2)
{
  __int64 v2; // x21
  int v4; // w0
  int v5; // w20
  int v6; // w9
  bool v7; // zf
  __int64 v8; // x8

  v2 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a2 + 96) + 24LL) + 152LL);
  if ( *(_QWORD *)(v2 + 16) && (((unsigned __int64)*(int *)(v2 + 200) >> *(_DWORD *)(a2 + 8)) & 1) != 0 )
  {
    if ( *(_QWORD *)(v2 + 48) )
    {
      v4 = regulator_disable();
      if ( v4 )
      {
        v5 = v4;
        if ( (unsigned int)__ratelimit(&qmp_disable_regulator__rs, "qmp_disable_regulator") )
          dev_err(*(_QWORD *)(v2 + 8), "qmp regulator disable failed %d", v5);
      }
    }
    v6 = *(_DWORD *)(v2 + 200);
    v7 = (v6 & ~(unsigned int)(1LL << *(_DWORD *)(a2 + 8))) == 0;
    *(_DWORD *)(v2 + 200) = v6 & ~(unsigned int)(1LL << *(_DWORD *)(a2 + 8));
    if ( v7 )
    {
      *(_BYTE *)(*(_QWORD *)(v2 + 16) + 64LL) = 0;
      *(_BYTE *)(*(_QWORD *)(v2 + 16) + 1009LL) = 0;
      v8 = *(unsigned int *)(a2 + 8);
      if ( (unsigned int)v8 >= 3 )
      {
        __break(0x5512u);
        qmp_sdca_dmic_hw_params();
      }
      else
      {
        *(_BYTE *)(v2 + v8 + 204) = 0;
        *(_BYTE *)(v2 + 207) = 0;
      }
    }
  }
}
