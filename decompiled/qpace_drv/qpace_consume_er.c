__int64 __fastcall qpace_consume_er(
        int a1,
        void (__fastcall *a2)(unsigned __int64, unsigned __int64),
        void (__fastcall *a3)(unsigned __int64, unsigned __int64),
        char a4)
{
  __int64 v6; // x24
  unsigned int v9; // w19
  __int64 v10; // x26
  unsigned __int64 v11; // x8
  __int64 v12; // x27
  unsigned __int64 v13; // x28
  unsigned __int64 v14; // x9
  __int64 v15; // x10
  unsigned __int64 v16; // x12
  unsigned int v17; // w11
  unsigned __int64 v18; // x25
  unsigned __int64 v19; // x1
  void (__fastcall *v20)(unsigned __int64, unsigned __int64); // x8
  _QWORD *v21; // x8
  __int64 v22; // x9
  __int64 v23; // x10
  __int64 v24; // x9
  __int64 v25; // x10
  __int64 v26; // x8
  unsigned __int64 v27; // x12
  __int64 v28; // x10
  __int64 v29; // x8
  int v30; // w9
  __int64 v31; // x20
  __int64 v32; // x22
  __int64 v33; // x21
  __int64 v34; // x8
  __int64 v35; // x10
  __int64 v36; // x8
  __int64 v37; // x9
  char v39; // [xsp+Ch] [xbp-4h]

  v6 = a1;
  v9 = 0;
  v10 = ev_rings + ((__int64)a1 << 6);
  v11 = *(_QWORD *)(v10 + 32);
  v12 = *(_QWORD *)(v10 + 40);
  if ( v12 == v11 + 4064 )
    v13 = *(_QWORD *)(v10 + 32);
  else
    v13 = v12 + 32;
  v39 = *(_BYTE *)(v10 + 56);
  *(_QWORD *)(v10 + 40) = v13;
  while ( 1 )
  {
    v14 = v11 + 4096;
    if ( v13 < v11 + 4096 )
    {
      v15 = *(_QWORD *)(v13 + 16);
      if ( (((unsigned int)v15 >> 30) & 1) == *(_BYTE *)(v10 + 56) )
      {
        v16 = v13 + 32;
        v17 = v9 + 1;
        v18 = v13;
        do
        {
          v19 = (v18 - v11) >> 5;
          if ( (v15 & 0xF00000) != 0 )
            v20 = a3;
          else
            v20 = a2;
          v13 = v16;
          v9 = v17;
          if ( *((_DWORD *)v20 - 1) != -813680784 )
            __break(0x8228u);
          v20(v16 - 32, v19);
          v11 = *(_QWORD *)(v10 + 32);
          v14 = v11 + 4096;
          if ( v13 >= v11 + 4096 )
            break;
          v15 = *(_QWORD *)(v13 + 16);
          v18 += 32LL;
          v16 = v13 + 32;
          v17 = v9 + 1;
        }
        while ( (((unsigned int)v15 >> 30) & 1) == *(_BYTE *)(v10 + 56) );
      }
    }
    if ( v13 != v14 )
      break;
    v13 = v11;
    *(_BYTE *)(v10 + 56) ^= 1u;
  }
  if ( (a4 & 1) != 0 )
  {
    *(_QWORD *)(v10 + 48) = v13;
    v21 = (_QWORD *)(ev_rings + (v6 << 6));
    v22 = v21[6];
    v23 = v21[4];
    if ( v22 == v23 )
      v24 = v23 + 4064;
    else
      v24 = v22 - 32;
    v25 = v24 << 8 >> 8;
    v21[5] = v24;
    v26 = v25 + 0x8000000000LL;
    v27 = (unsigned __int64)(v25 + 0x8000000000LL) >> 38;
    v28 = v25 - kimage_voffset;
    v29 = v26 + memstart_addr;
    v30 = a1 << 12;
    if ( v27 )
      v31 = v28;
    else
      v31 = v29;
    v32 = v30;
    writel(HIDWORD(v31), (unsigned int *)(qpace_er_regs + v30 + 28));
    writel(v31, (unsigned int *)(qpace_er_regs + v32 + 24));
    v33 = tr_rings;
    mutex_lock(&qpace_ref_lock);
    v34 = v33 + 32 * v6;
    v35 = *(_QWORD *)(v34 + 24);
    *(_QWORD *)(v34 + 24) = v35 - (int)v9;
    if ( v35 == v9 && !--active_rings )
    {
      dev_pm_qos_update_request(&qos_req, 0x7FFFFFFF);
      pm_relax(qpace_dev);
      rings_inited_since_activation = 0;
    }
    mutex_unlock(&qpace_ref_lock);
    v36 = tr_rings + 32 * v6;
    v37 = *(_QWORD *)v36
        + 32LL * (((_BYTE)v9 + (unsigned __int8)((*(_DWORD *)(v36 + 8) - (unsigned int)*(_QWORD *)v36) >> 5)) & 0x7F);
    *(_QWORD *)(v36 + 8) = v37;
    *(_DWORD *)(v37 + 28) |= 0x80000u;
  }
  else
  {
    *(_QWORD *)(v10 + 40) = v12;
    *(_BYTE *)(v10 + 56) = v39;
  }
  return v9;
}
