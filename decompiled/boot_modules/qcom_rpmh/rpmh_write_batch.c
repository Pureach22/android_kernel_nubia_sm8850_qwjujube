__int64 __fastcall rpmh_write_batch(__int64 a1, unsigned int a2, void *src, unsigned int *a4)
{
  __int64 result; // x0
  _BYTE *v5; // x19
  void *v6; // x21
  unsigned int *v7; // x22
  char v8; // w23
  unsigned int *v9; // x21
  void *v10; // x22
  __int64 v12; // x0
  __int64 v13; // x1
  unsigned int v14; // w8
  __int64 v15; // x20
  _QWORD *v16; // x9
  int v17; // w10
  const void *v18; // x1
  __int64 v19; // x22
  _QWORD *v20; // x23
  unsigned int v21; // w24
  _QWORD *v22; // x21
  unsigned int v23; // w21
  __int64 v24; // x21
  unsigned int v25; // w0
  __int64 v26; // x3
  __int64 v27; // x4
  __int64 v28; // x5
  unsigned int v29; // w19
  _QWORD v30[2]; // [xsp+0h] [xbp-110h] BYREF
  _QWORD v31[2]; // [xsp+10h] [xbp-100h] BYREF
  unsigned int v32[2]; // [xsp+20h] [xbp-F0h] BYREF
  __int64 v33; // [xsp+28h] [xbp-E8h]
  unsigned int *v34; // [xsp+30h] [xbp-E0h]
  _QWORD v35[27]; // [xsp+38h] [xbp-D8h] BYREF

  v35[26] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v35[24] = v30;
  v31[0] = v31;
  v31[1] = v31;
  v32[0] = a2;
  v32[1] = 1;
  v30[0] = 0;
  v30[1] = 0;
  v33 = 0;
  v34 = (unsigned int *)v35;
  memset(v35, 0, 192);
  v35[25] = a1;
  if ( (rpmh_standalone & 1) != 0 )
    goto LABEL_2;
  v5 = *(_BYTE **)(*(_QWORD *)(a1 + 96) + 152LL);
  if ( a2 == 2 )
  {
    if ( (v5[1160] & 1) != 0 )
    {
      v6 = src;
      v7 = a4;
      raw_spin_lock(v5 + 1152);
      v8 = v5[1157];
      raw_spin_unlock(v5 + 1152);
      a4 = v7;
      src = v6;
      if ( (v8 & 1) != 0 )
      {
        result = 4294967280LL;
        goto LABEL_12;
      }
    }
    result = 4294967274LL;
    if ( !src )
      goto LABEL_12;
    v24 = *a4;
    if ( (unsigned int)(v24 - 17) < 0xFFFFFFF0 )
      goto LABEL_12;
    memcpy(v35, src, 12 * v24);
    v34 = (unsigned int *)v35;
    v32[0] = 2;
    LODWORD(v33) = v24;
    result = rpmh_rsc_get_channel((__int64)v5);
    if ( (result & 0x80000000) != 0 )
      goto LABEL_12;
    v25 = rpmh_rsc_send_data((__int64)v5, v32, result);
    if ( !v25 )
    {
      if ( (unsigned int)wait_for_completion_timeout(v30, 1250) )
      {
LABEL_2:
        result = 0;
LABEL_12:
        _ReadStatusReg(SP_EL0);
        return result;
      }
      v25 = rpmh_rsc_debug((__int64)v5, v30);
      __break(0x800u);
    }
    v29 = v25;
    printk(&unk_DA9D, v25, *v34, v26, v27, v28);
    result = v29;
    goto LABEL_12;
  }
  v9 = a4;
  v10 = src;
  v12 = raw_spin_lock_irqsave(v5 + 1152);
  if ( a2 < 3 )
  {
    v14 = a2;
    v15 = v12;
    v16 = &v5[232 * v14];
    v17 = -22;
    v16[174] = 0;
    v16[173] = 0;
    v16[172] = 0;
    v16[171] = 0;
    v16[170] = 0;
    v16[169] = 0;
    v16[168] = 0;
    v16[167] = 0;
    v16[166] = 0;
    v16[165] = 0;
    v16[164] = 0;
    v16[163] = 0;
    v16[162] = 0;
    v16[161] = 0;
    v16[160] = 0;
    v16[159] = 0;
    v16[158] = 0;
    v16[157] = 0;
    v16[156] = 0;
    v16[155] = 0;
    v16[154] = 0;
    v16[153] = 0;
    v16[152] = 0;
    v16[151] = 0;
    v16[150] = 0;
    v16[149] = 0;
    v16[148] = 0;
    v16[147] = 0;
    v16[146] = 0;
    if ( v10 )
    {
      v18 = v10;
      v19 = *v9;
      if ( (unsigned int)(v19 - 17) >= 0xFFFFFFF0 )
      {
        v20 = v16 + 146;
        v21 = v14;
        v22 = v16 + 149;
        memcpy(v16 + 149, v18, 12 * v19);
        v17 = 0;
        *(_DWORD *)v20 = v21;
        v20[2] = v22;
        *((_DWORD *)v20 + 2) = v19;
      }
    }
    v5[1156] = 1;
    v23 = v17;
    raw_spin_unlock_irqrestore(v5 + 1152, v15);
    result = v23;
    goto LABEL_12;
  }
  __break(0x5512u);
  return rpmh_flush(v12, v13);
}
