__int64 __fastcall configure_cpucp_map(unsigned int a1)
{
  _DWORD **v1; // x8
  char v2; // w17
  __int64 v3; // x12
  bool v4; // cc
  unsigned __int64 v5; // x17
  unsigned __int64 v6; // x17
  __int64 v7; // x0
  __int64 v8; // x1
  __int64 i; // x3
  __int64 v10; // x4
  __int64 v11; // x5
  __int64 v12; // x6
  __int64 v13; // x6
  __int64 result; // x0
  _DWORD *v15; // x8
  __int64 v16; // x0
  unsigned int v17; // w19
  _QWORD v18[9]; // [xsp+8h] [xbp-98h] BYREF
  __int64 v19; // [xsp+50h] [xbp-50h] BYREF
  __int64 v20; // [xsp+58h] [xbp-48h]
  __int64 v21; // [xsp+60h] [xbp-40h]
  __int64 v22; // [xsp+68h] [xbp-38h]
  __int64 v23; // [xsp+70h] [xbp-30h]
  __int64 v24; // [xsp+78h] [xbp-28h]
  __int64 v25; // [xsp+80h] [xbp-20h]
  __int64 v26; // [xsp+88h] [xbp-18h]
  __int64 v27; // [xsp+90h] [xbp-10h]
  __int64 v28; // [xsp+98h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( qcom_pmu_inited == 1 )
  {
    v1 = (_DWORD **)ops;
    if ( ops )
    {
      v2 = 0;
      v3 = a1;
      v26 = -1;
      v27 = -1;
      v24 = -1;
      v25 = -1;
      v22 = -1;
      v23 = -1;
      v20 = -1;
      v21 = -1;
      v19 = -1;
      do
      {
        v5 = v3 & (-1LL << v2);
        if ( !v5 )
          break;
        v6 = __clz(__rbit64(v5));
        if ( v6 >= 0x20 )
          break;
        v7 = *(_QWORD *)((char *)&cpu_ev_data + _per_cpu_offset[v6]);
        v8 = *(unsigned int *)(v7 + 328);
        if ( (_DWORD)v8 )
        {
          for ( i = 0; 40 * v8 != i; i += 40 )
          {
            if ( i == 360 )
LABEL_27:
              __break(0x5512u);
            v10 = *(unsigned int *)(v7 + i + 44);
            if ( (unsigned int)v10 <= 8 && *((_BYTE *)&cpucp_map + 16 * v10) == 1 && *(_DWORD *)(v7 + i + 40) >= 4u )
            {
              v11 = *(_QWORD *)(v7 + i + 16);
              if ( v11 )
              {
                if ( (*((_QWORD *)&cpucp_map + 2 * v10 + 1) & (1LL << v6)) != 0 )
                {
                  v12 = (unsigned int)phys_cpu[v6];
                  if ( (unsigned int)v12 > 7 )
                    goto LABEL_27;
                  v13 = 9 * v12;
                  if ( (unsigned __int64)(v13 + v10) > 0x47 )
                  {
                    __break(1u);
                    goto LABEL_20;
                  }
                  *((_BYTE *)&v19 + v13 + v10) = *(_DWORD *)(v11 + 396);
                }
              }
            }
          }
        }
        v4 = v6 > 0x1E;
        v2 = v6 + 1;
      }
      while ( !v4 );
      v18[2] = v21;
      v18[3] = v22;
      v18[7] = v26;
      v18[8] = v27;
      v18[5] = v24;
      v18[6] = v25;
      v18[4] = v23;
      v18[0] = v19;
      v18[1] = v20;
      v15 = *v1;
      v16 = ph;
      if ( *(v15 - 1) != 1737159351 )
        __break(0x8228u);
      result = ((__int64 (__fastcall *)(__int64, _QWORD *, __int64, __int64, __int64))v15)(
                 v16,
                 v18,
                 0x504D554D4150LL,
                 11,
                 72);
      if ( (result & 0x80000000) != 0 )
      {
        v17 = result;
        printk(&unk_8EE9);
        result = v17;
      }
    }
    else
    {
      result = 0;
    }
  }
  else
  {
LABEL_20:
    result = 4294966779LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
