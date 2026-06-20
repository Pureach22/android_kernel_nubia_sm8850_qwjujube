__int64 __fastcall gen8_hwsched_snapshot(__int64 a1, __int64 a2)
{
  char v4; // w0
  char v5; // w21
  unsigned __int64 v6; // x27
  _QWORD *v7; // x28
  int v8; // w8
  __int64 result; // x0
  __int64 v10; // [xsp+8h] [xbp-18h] BYREF
  int v11; // [xsp+10h] [xbp-10h]
  int v12; // [xsp+14h] [xbp-Ch]
  __int64 v13; // [xsp+18h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  gen8_gmu_snapshot(a1, a2);
  adreno_hwsched_parse_fault_cmdobj(a1, a2);
  v4 = adreno_hwsched_parse_payload_rb(a1, a2);
  if ( *(_DWORD *)(a1 + 22440) )
  {
    v5 = v4;
    v6 = 0;
    v7 = (_QWORD *)(a1 + 20944);
    do
    {
      if ( v6 == 33 )
        __break(0x5512u);
      v8 = *((_DWORD *)v7 - 7);
      if ( (v8 != 1) | v5 & 1 )
      {
        if ( v8 != 2 )
          goto LABEL_7;
      }
      else
      {
        kgsl_snapshot_add_section(a1, 770, a2, adreno_hwsched_snapshot_rb, *v7);
        v8 = *((_DWORD *)v7 - 7);
        if ( v8 != 2 )
        {
LABEL_7:
          if ( v8 != 14 )
            goto LABEL_8;
          goto LABEL_16;
        }
      }
      kgsl_snapshot_add_section(a1, 2818, a2, adreno_snapshot_global, *v7);
      v8 = *((_DWORD *)v7 - 7);
      if ( v8 != 14 )
      {
LABEL_8:
        if ( v8 != 3 )
          goto LABEL_9;
        goto LABEL_17;
      }
LABEL_16:
      kgsl_snapshot_add_section(a1, 2818, a2, adreno_snapshot_global, *v7);
      v8 = *((_DWORD *)v7 - 7);
      if ( v8 != 3 )
      {
LABEL_9:
        if ( v8 != 4 )
          goto LABEL_10;
        goto LABEL_18;
      }
LABEL_17:
      kgsl_snapshot_add_section(a1, 2818, a2, adreno_snapshot_global, *v7);
      v8 = *((_DWORD *)v7 - 7);
      if ( v8 != 4 )
      {
LABEL_10:
        if ( v8 != 24 )
          goto LABEL_11;
        goto LABEL_19;
      }
LABEL_18:
      adreno_hwsched_snapshot_preemption_records(a1, a2, *v7);
      v8 = *((_DWORD *)v7 - 7);
      if ( v8 != 24 )
      {
LABEL_11:
        if ( v8 != 25 )
          goto LABEL_12;
        goto LABEL_20;
      }
LABEL_19:
      kgsl_snapshot_add_section(a1, 2818, a2, adreno_snapshot_global, *v7);
      v8 = *((_DWORD *)v7 - 7);
      if ( v8 != 25 )
      {
LABEL_12:
        if ( v8 == 23 )
          goto LABEL_21;
        goto LABEL_3;
      }
LABEL_20:
      kgsl_snapshot_add_section(a1, 2818, a2, adreno_hwsched_snapshot_aqe_buffer, *v7);
      if ( *((_DWORD *)v7 - 7) == 23 )
      {
LABEL_21:
        v10 = *v7;
        v12 = 0;
        v11 = 7;
        kgsl_snapshot_add_section(a1, 5889, a2, adreno_snapshot_gmu_mem, &v10);
      }
LABEL_3:
      ++v6;
      v7 += 6;
    }
    while ( v6 < *(unsigned int *)(a1 + 22440) );
  }
  result = adreno_hwsched_snapshot_context_queue(a1, a2);
  _ReadStatusReg(SP_EL0);
  return result;
}
