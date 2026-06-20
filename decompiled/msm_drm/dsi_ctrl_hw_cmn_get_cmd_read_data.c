__int64 __fastcall dsi_ctrl_hw_cmn_get_cmd_read_data(
        __int64 *a1,
        _DWORD *a2,
        int a3,
        unsigned int a4,
        int a5,
        unsigned int *a6)
{
  __int64 v12; // x8
  unsigned int v13; // w0
  int v14; // w8
  unsigned int v15; // w9
  unsigned int v16; // w5
  unsigned int v17; // w25
  int v18; // w3
  int v19; // w3
  unsigned int v20; // w23
  int v21; // w3
  int v22; // w9
  int v23; // w8
  unsigned int v24; // w24
  unsigned int *v25; // x21
  _DWORD *v26; // x22
  unsigned __int64 v27; // x26
  _QWORD *v28; // x28
  int v29; // w25
  __int64 v30; // x27
  _DWORD *v31; // x8
  unsigned int v32; // w0
  unsigned __int64 v33; // x8
  unsigned __int64 v34; // x9
  unsigned __int64 v35; // x10
  unsigned __int64 v36; // x11
  _DWORD *v37; // x15
  unsigned __int64 v38; // x10
  unsigned __int64 v39; // x10
  __int64 v40; // x12
  unsigned __int64 v41; // x14
  __int64 v42; // x11
  unsigned __int64 v43; // x12
  char *v44; // x13
  __int16 v45; // w14
  unsigned __int64 v46; // x9
  _BYTE *v47; // x10
  char v48; // w12
  int v49; // w4
  _DWORD *v51; // [xsp+0h] [xbp-20h]
  _QWORD v52[3]; // [xsp+8h] [xbp-18h] BYREF

  v52[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *a1;
  v52[0] = 0;
  v52[1] = 0;
  v13 = readl_relaxed_19((unsigned int *)(v12 + 468));
  v14 = a5 + 10;
  v15 = HIWORD(v13);
  if ( a4 == 4 )
    v14 = 8;
  if ( v15 == v14 )
    v16 = v15 - 4;
  else
    v16 = HIWORD(v13);
  if ( !v16 )
  {
    if ( a1 )
      v19 = *((_DWORD *)a1 + 14);
    else
      v19 = -1;
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: DSI_%d: Panel detected error, no data read\n", v19);
    a4 = 0;
    goto LABEL_65;
  }
  v17 = a4 + 3;
  v51 = a2;
  if ( a4 == 4 && v16 >= 5 )
  {
    if ( a1 )
      v18 = *((_DWORD *)a1 + 14);
    else
      v18 = -1;
    v20 = 4;
    drm_dev_printk(
      0,
      &unk_2597DF,
      "[msm-dsi-info]: DSI_%d: Expected %u bytes for short read but received %u bytes\n",
      v18,
      4,
      v16);
    v24 = 0;
    goto LABEL_29;
  }
  if ( a4 == 16 && (v20 = a5 + 6, v16 > v20) )
  {
    if ( a1 )
      v21 = *((_DWORD *)a1 + 14);
    else
      v21 = -1;
    drm_dev_printk(
      0,
      &unk_2597DF,
      "[msm-dsi-info]: DSI_%d: Expected %u bytes for long read but received %u bytes\n",
      v21,
      v20,
      v16);
    if ( v20 < 0x11 )
    {
LABEL_68:
      v24 = 0;
      if ( v17 >= 4 )
        goto LABEL_29;
      goto LABEL_39;
    }
  }
  else
  {
    v20 = v16;
    if ( v16 < 0x11 )
      goto LABEL_68;
  }
  v22 = 4 - (v20 - a4);
  if ( (int)(v20 - a4) <= 3 )
    v23 = 0;
  else
    v23 = 4 - (v20 - a4);
  if ( (int)(v20 - a4) > 3 )
    v22 = 0;
  v24 = a3 + v23 + v22 - 4;
  if ( v17 >= 4 )
  {
LABEL_29:
    v25 = a6;
    v26 = v51;
    v27 = 0;
    v28 = v52;
    if ( v17 >> 2 >= 4 )
      v29 = 4;
    else
      v29 = v17 >> 2;
    v30 = (unsigned int)(4 * v29 + 104);
    do
    {
      v32 = readl_relaxed_19((unsigned int *)(*a1 + v30));
      if ( v24 )
      {
        if ( v27 > 0xC )
        {
LABEL_70:
          __break(1u);
          goto LABEL_71;
        }
        v31 = v28;
        v27 += 4LL;
        v28 = (_QWORD *)((char *)v28 + 4);
      }
      else
      {
        v31 = v26++;
      }
      --v29;
      v30 -= 4;
      *v31 = bswap32(v32);
    }
    while ( v29 );
    a6 = v25;
  }
LABEL_39:
  if ( v24 && (int)v24 <= 15 )
  {
    v33 = v24;
    LODWORD(v34) = 16 - v24;
    if ( v24 <= 0x10 )
      v34 = (unsigned int)v34;
    else
      v34 = 0;
    v35 = 16LL - v24;
    if ( v24 > 0x10uLL )
      v35 = 0;
    if ( v35 >= 15 - (unsigned __int64)v24 )
      v35 = 15LL - v24;
    if ( v35 >= v34 )
      v36 = v34;
    else
      v36 = v35;
    if ( v36 >= 2 )
    {
      v39 = v36 + 1;
      v40 = 2;
      v37 = v51;
      v41 = ~v36;
      if ( ((v36 + 1) & 1) != 0 )
        v40 = (v36 + 1) & 1;
      v42 = (__int64)v51 + 1;
      v38 = v39 - v40;
      v43 = v41 + v40;
      v33 = v38 + v24;
      v44 = (char *)v52 + v24 + 1;
      do
      {
        v45 = *(_WORD *)(v44 - 1);
        v43 += 2LL;
        v44 += 2;
        *(_WORD *)(v42 - 1) = v45;
        v42 += 2;
      }
      while ( v43 );
    }
    else
    {
      v37 = v51;
      v38 = 0;
    }
    v46 = v34 - v38;
    v47 = (char *)v37 + v38;
    while ( v46 )
    {
      if ( v33 > 0xF )
        goto LABEL_70;
      v48 = *((_BYTE *)v52 + v33++);
      --v46;
      *v47++ = v48;
      if ( v33 == 16 )
        goto LABEL_61;
    }
LABEL_71:
    __break(0x5512u);
  }
LABEL_61:
  *a6 = v20;
  if ( a1 )
    v49 = *((_DWORD *)a1 + 14);
  else
    v49 = -1;
  _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: DSI_%d: Read %d bytes\n", v49, a4);
LABEL_65:
  _ReadStatusReg(SP_EL0);
  return a4;
}
