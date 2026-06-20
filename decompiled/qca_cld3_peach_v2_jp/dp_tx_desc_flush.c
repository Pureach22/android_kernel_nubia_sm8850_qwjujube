__int64 __fastcall dp_tx_desc_flush(
        __int64 result,
        __int64 a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v12; // x20
  __int64 v14; // x23
  unsigned __int16 *v15; // x28
  int v16; // w27
  unsigned int v17; // w21
  unsigned int v18; // w26
  __int64 v19; // x0
  __int64 v20; // x8
  __int64 v21; // x24
  int v22; // w8
  __int64 v23; // x8
  unsigned __int64 StatusReg; // [xsp+0h] [xbp-10h]
  __int64 v25; // [xsp+8h] [xbp-8h]

  v12 = result;
  v25 = *(_QWORD *)(result + 8);
  if ( a2 || (a3 & 1) != 0 )
  {
    v14 = 0;
    StatusReg = _ReadStatusReg(SP_EL0);
    while ( 1 )
    {
      v15 = (unsigned __int16 *)(v25 + 2256 + 296 * v14);
      if ( v15[28] )
      {
        if ( *((_DWORD *)v15 + 16) != 6 && *((_QWORD *)v15 + 4) )
          break;
      }
LABEL_7:
      if ( ++v14 == 6 )
        return result;
    }
    if ( (a3 & 1) != 0 )
      goto LABEL_16;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      result = raw_spin_lock(v15 + 128);
LABEL_16:
      v16 = v15[28];
      if ( v15[28] )
        goto LABEL_17;
      goto LABEL_30;
    }
    result = raw_spin_lock_bh(v15 + 128);
    *((_QWORD *)v15 + 33) |= 1uLL;
    v16 = v15[28];
    if ( !v15[28] )
    {
LABEL_30:
      if ( (a3 & 1) == 0 )
      {
        v23 = *((_QWORD *)v15 + 33);
        if ( (v23 & 1) != 0 )
        {
          *((_QWORD *)v15 + 33) = v23 & 0xFFFFFFFFFFFFFFFELL;
          result = raw_spin_unlock_bh(v15 + 128);
        }
        else
        {
          result = raw_spin_unlock(v15 + 128);
        }
      }
      goto LABEL_7;
    }
LABEL_17:
    v17 = v15[8];
    v18 = 0;
    while ( 1 )
    {
      v20 = *((_QWORD *)v15 + 4);
      if ( !v20 )
        goto LABEL_30;
      v21 = *(_QWORD *)(v20 + 8LL * (unsigned __int16)(v18 / v17)) + (int)(v18 % v17 * *v15);
      if ( v21 )
      {
        v22 = *(_DWORD *)(v21 + 32);
        if ( (v22 & 0x200) != 0 )
        {
          if ( a2 )
          {
            if ( *(unsigned __int8 *)(v21 + 48) == *(unsigned __int8 *)(a2 + 59) )
              goto LABEL_27;
          }
          else if ( *(_QWORD *)(v21 + 56) == v12 )
          {
LABEL_27:
            if ( (a3 & 1) != 0 )
            {
              *(_DWORD *)(v21 + 32) = v22 | 0x2000;
              v19 = dp_tx_comp_free_buf(v25, v21, 0, a4, a5, a6, a7, a8, a9, a10, a11);
              result = dp_tx_desc_release(v19, v21, v14);
            }
            else
            {
              *(_BYTE *)(v21 + 48) = -1;
            }
          }
        }
      }
      if ( v16 == ++v18 )
        goto LABEL_30;
    }
  }
  return qdf_trace_msg(
           0x45u,
           2u,
           "%s: Reset TX desc vdev, Vdev param is required!",
           a4,
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           "dp_tx_desc_flush");
}
