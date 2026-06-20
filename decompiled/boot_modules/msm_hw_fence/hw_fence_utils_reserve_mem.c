__int64 __fastcall hw_fence_utils_reserve_mem(
        unsigned __int64 a1,
        unsigned int a2,
        _QWORD *a3,
        _QWORD *a4,
        unsigned int *a5,
        unsigned int a6)
{
  __int64 v6; // x30
  __int64 v7; // x20
  unsigned __int64 v8; // x21
  unsigned __int64 v9; // x8
  unsigned int v10; // w9
  int v11; // w8
  unsigned int v12; // w19
  unsigned int v13; // w7
  _DWORD *v14; // x9
  unsigned __int64 v15; // x6
  __int64 v16; // x4
  _QWORD *v18; // x23
  const char *v19; // x3
  _QWORD *v20; // x24
  __int64 v21; // x4
  unsigned __int64 v22; // x25
  unsigned int v23; // w19
  _QWORD *v24; // x22
  _QWORD *v25; // x23

  v7 = v6;
  if ( (int)a2 <= 1 )
  {
    if ( a2 )
    {
      if ( a2 == 1 )
      {
        v11 = *(_DWORD *)(a1 + 56);
        LODWORD(v8) = *(_DWORD *)(a1 + 32);
        v12 = 0;
LABEL_12:
        v13 = v11 << 6;
        goto LABEL_19;
      }
LABEL_33:
      v23 = a2;
      v8 = a1;
      v24 = a3;
      v25 = a4;
      printk(&unk_2B4FD, "hw_fence_utils_reserve_mem", 1490, v6, a2);
      v13 = *a5;
      a2 = v23;
      a1 = v8;
      a4 = v25;
      a3 = v24;
      LODWORD(v8) = 0;
      v12 = -22;
      v15 = *(_QWORD *)(a1 + 416);
      if ( !*a5 )
        goto LABEL_34;
LABEL_20:
      if ( v15 >= v13 + (unsigned int)v8 )
      {
        if ( (~msm_hw_fence_debug_level & 0x10008) == 0 )
        {
          if ( a2 > 4 )
          {
            v21 = a2;
            v18 = a4;
            v20 = a3;
            v19 = "Unknown";
          }
          else
          {
            v18 = a4;
            v19 = off_2C400[a2];
            v20 = a3;
            v21 = a2;
          }
          v22 = a1;
          printk(&unk_24AAB, "hw_fence_utils_reserve_mem", 1503, v19, v21);
          a1 = v22;
          a3 = v20;
          a4 = v18;
        }
        *a3 = *(_QWORD *)(a1 + 320) + (unsigned int)v8;
        v16 = *(_QWORD *)(a1 + 312) + (unsigned int)v8;
        *a4 = v16;
        if ( (~msm_hw_fence_debug_level & 0x10001) == 0 )
          printk(&unk_2376F, "hw_fence_utils_reserve_mem", 1508, *a3, v16);
        return v12;
      }
LABEL_34:
      printk(&unk_21F56, "hw_fence_utils_reserve_mem", 1497, v7, v13);
      return (unsigned int)-12;
    }
    v13 = *(_DWORD *)(a1 + 32);
    LODWORD(v8) = 0;
    goto LABEL_18;
  }
  if ( a2 == 2 )
  {
    v12 = 0;
    v13 = *(_DWORD *)(a1 + 20);
    LODWORD(v8) = *(_DWORD *)(a1 + 32) + (*(_DWORD *)(a1 + 56) << 6);
    goto LABEL_19;
  }
  if ( a2 == 3 )
  {
    if ( *(_DWORD *)(a1 + 60) <= a6 || (v14 = (_DWORD *)(*(_QWORD *)(a1 + 40) + 16LL * (int)a6), !*(_QWORD *)v14) )
    {
      printk(&unk_2559E, "hw_fence_utils_reserve_mem", 1465, v6, a6);
      return (unsigned int)-22;
    }
    v13 = *(_DWORD *)(*(_QWORD *)v14 + 36LL);
    LODWORD(v8) = v14[2];
LABEL_18:
    v12 = 0;
LABEL_19:
    *a5 = v13;
    v15 = *(_QWORD *)(a1 + 416);
    if ( !v13 )
      goto LABEL_34;
    goto LABEL_20;
  }
  if ( a2 != 4 )
    goto LABEL_33;
  v8 = *(unsigned int *)(a1 + 460);
  v9 = *(_QWORD *)(a1 + 416);
  if ( v9 > v8 )
  {
    v10 = v9 - v8;
    if ( (unsigned int)(v9 - v8) > 0x3F )
    {
      v11 = v10 >> 6;
      v12 = 0;
      if ( v10 >> 6 >= 0x3E8 )
        v11 = 1000;
      goto LABEL_12;
    }
  }
  if ( (~msm_hw_fence_debug_level & 0x10004) == 0 )
    printk(&unk_22DBA, "hw_fence_utils_reserve_mem", 1479, v9, (unsigned int)v8);
  return (unsigned int)-12;
}
