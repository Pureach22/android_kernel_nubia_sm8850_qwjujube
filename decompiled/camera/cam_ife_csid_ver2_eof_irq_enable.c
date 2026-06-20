__int64 __fastcall cam_ife_csid_ver2_eof_irq_enable(__int64 result, unsigned __int8 *a2)
{
  __int64 v2; // x19
  __int64 v3; // x8
  int v4; // w20
  __int64 v5; // x21
  __int64 v6; // x22
  int v7; // w1
  __int64 *v8; // x9
  int *v9; // x8
  __int64 v10; // x0
  __int64 v11; // x8
  int v12; // w10
  __int64 v13; // x6
  const char *v14; // x7
  const char *v15; // x5
  __int64 v16; // x1
  __int64 v17; // x2
  __int64 v18; // x4
  int v19; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v20; // [xsp+8h] [xbp-8h]

  v2 = result;
  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(result + 31128);
  v4 = *a2;
  v19 = 0;
  if ( *(_DWORD *)(v3 + 92) )
  {
    v5 = 0;
    v6 = **(_QWORD **)(result + 31136);
    while ( 1 )
    {
      v11 = *(_QWORD *)(v2 + v5 + 24);
      if ( !v11 )
        goto LABEL_5;
      v7 = *(_DWORD *)(v11 + 208);
      if ( !v7 )
        goto LABEL_5;
      v12 = *(_DWORD *)(v2 + v5 + 4);
      if ( v12 )
      {
        if ( v12 != 5 )
          goto LABEL_5;
        if ( (*(_BYTE *)(*(_QWORD *)(v6 + 120) + 828LL) & 0x80) != 0 )
        {
          v7 = *(_DWORD *)(v2 + 32232);
          v8 = (__int64 *)(v2 + 30984);
          v9 = (int *)(*(_QWORD *)(v6 + 240) + 16LL);
        }
        else
        {
          v8 = (__int64 *)(v2 + 31056);
          v9 = (int *)(*(_QWORD *)(v11 + 264) + 524LL);
        }
      }
      else
      {
        if ( *(_BYTE *)(v2 + v5 + 144) != 1 )
          goto LABEL_5;
        v8 = (__int64 *)(v2 + 31016);
        v9 = (int *)(*(_QWORD *)(v11 + 264) + 524LL);
      }
      v10 = *v8;
      v19 = *v9;
      result = cam_irq_controller_update_irq(v10, v7, v4, (__int64)&v19);
LABEL_5:
      v5 += 152;
      if ( v5 == 1824 )
      {
        *(_BYTE *)(v2 + 2151) = v4;
        if ( (debug_mdl & 8) != 0 && !debug_priority )
        {
          v13 = *(unsigned int *)(*(_QWORD *)(v2 + 31120) + 4LL);
          if ( v4 )
            v14 = "enabled";
          else
            v14 = "disabled";
          v15 = "CSID[%u] EOF IRQ %s";
          v16 = debug_mdl & 8;
          v17 = 4;
          v18 = 744;
          goto LABEL_24;
        }
        goto LABEL_25;
      }
    }
  }
  v13 = *(unsigned int *)(*(_QWORD *)(result + 31120) + 4LL);
  if ( v4 )
    v14 = "enable";
  else
    v14 = "disable";
  v15 = "CSID[%u] powered down unable to %s CSID EOF IRQ";
  v16 = 8;
  v17 = 2;
  v18 = 700;
LABEL_24:
  result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, const char *))cam_print_log)(
             3,
             v16,
             v17,
             "cam_ife_csid_ver2_eof_irq_enable",
             v18,
             v15,
             v13,
             v14);
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return result;
}
