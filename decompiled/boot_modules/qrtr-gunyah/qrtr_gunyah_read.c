__int64 __fastcall qrtr_gunyah_read(__int64 a1)
{
  unsigned int *v2; // x12
  __int64 v3; // x11
  __int64 v4; // x9
  unsigned __int64 v5; // x8
  unsigned __int64 v6; // x10
  __int64 v7; // x10
  unsigned __int64 v8; // x11
  unsigned __int64 v9; // x12
  unsigned __int64 v10; // x20
  int v11; // w11
  unsigned __int64 v12; // x9
  unsigned __int64 v13; // x22
  unsigned __int64 v14; // x24
  __int64 v15; // x25
  _DWORD *v16; // x8
  unsigned __int64 v17; // x10
  unsigned __int64 v18; // x9
  unsigned __int64 v19; // x2
  unsigned __int64 v20; // x9
  int v21; // w10
  unsigned __int64 v22; // x9
  __int64 v23; // x24
  unsigned __int64 v24; // x20
  signed int v25; // w0
  unsigned __int64 v26; // x24
  __int64 v27; // x10
  __int64 v28; // x8
  unsigned __int64 v29; // x9
  unsigned __int64 v30; // x20
  unsigned __int64 v31; // x22
  int v32; // w10
  unsigned __int64 v33; // x8
  unsigned __int64 v34; // x27
  __int64 v35; // x25
  unsigned __int64 v36; // x26
  _DWORD *v37; // x8
  unsigned __int64 v38; // x10
  unsigned __int64 v39; // x9
  __int64 v40; // x0
  int v41; // w0
  unsigned __int64 v42; // x9
  unsigned __int64 v43; // x25
  _DWORD *v44; // x8
  unsigned __int64 v45; // x10
  unsigned __int64 v46; // x9
  __int64 result; // x0
  __int64 v48; // [xsp+0h] [xbp-30h]
  _QWORD v49[5]; // [xsp+8h] [xbp-28h] BYREF

  v49[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v48 = raw_spin_lock_irqsave(a1 + 312);
  _wake_up(a1 + 400, 3, 0, 0);
  while ( 1 )
  {
    v2 = *(unsigned int **)(a1 + 360);
    v3 = **(unsigned int **)(a1 + 368);
    v4 = *v2;
    v5 = *(_QWORD *)(a1 + 392);
    v6 = (unsigned int)v3 >= (unsigned int)v4 ? (unsigned int)(v3 - v4) : v3 - v4 + v5;
    if ( v6 > v5 )
      break;
    if ( !v6 )
      goto LABEL_90;
    v7 = *(unsigned int *)(a1 + 48);
    if ( (_DWORD)v7 )
    {
      if ( (unsigned int)v3 >= (unsigned int)v4 )
        v8 = (unsigned int)(v3 - v4);
      else
        v8 = v3 - v4 + v5;
      if ( v8 > v5 )
      {
        __break(0x800u);
        v7 = *(unsigned int *)(a1 + 48);
        v8 = 0;
        LODWORD(v4) = **(_DWORD **)(a1 + 360);
        v5 = *(_QWORD *)(a1 + 392);
      }
      v9 = *(_QWORD *)(a1 + 40);
      if ( v8 + v7 <= v9 )
        v10 = v8;
      else
        v10 = v9 - v7;
      if ( v5 <= (unsigned int)v4 )
        v11 = v5;
      else
        v11 = 0;
      v12 = (unsigned int)(v4 - v11);
      v13 = v5 - v12;
      if ( v5 < v12 )
      {
        __break(0x800u);
      }
      else
      {
        if ( v13 >= v10 )
          v14 = v10;
        else
          v14 = v5 - v12;
        v15 = *(_QWORD *)(a1 + 32) + v7;
        if ( v14 )
          _memcpy_fromio(v15, *(_QWORD *)(a1 + 384) + v12, v14);
        if ( v13 < v10 )
          _memcpy_fromio(v15 + v14, *(_QWORD *)(a1 + 384), v10 - v14);
      }
      v16 = *(_DWORD **)(a1 + 360);
      v17 = *(_QWORD *)(a1 + 392);
      v18 = (unsigned int)(*v16 + v10);
      if ( v17 <= v18 )
        LODWORD(v18) = (unsigned int)v18 % (unsigned int)v17;
      *v16 = v18;
      v19 = v10 + *(unsigned int *)(a1 + 48);
      if ( v19 == *(_QWORD *)(a1 + 40) )
      {
        if ( (unsigned int)qrtr_endpoint_post(a1, *(_QWORD *)(a1 + 32), v19) == -22 )
          dev_err(*(_QWORD *)(a1 + 24), "invalid ipcrouter packet\n");
        *(_DWORD *)(a1 + 48) = 0;
        *(_QWORD *)(a1 + 40) = 0;
      }
      else
      {
        *(_DWORD *)(a1 + 48) = v19;
      }
    }
    else
    {
      memset(v49, 0, 32);
      v20 = *v2;
      if ( v5 <= v20 )
        v21 = v5;
      else
        v21 = 0;
      v22 = (unsigned int)(v20 - v21);
      if ( v5 < v22 )
      {
        __break(0x800u);
      }
      else
      {
        if ( v5 - v22 >= 0x20 )
          v23 = 32;
        else
          v23 = v5 - v22;
        v24 = v5 - v22;
        if ( v5 != v22 )
          _memcpy_fromio(v49, *(_QWORD *)(a1 + 384) + v22, v23);
        if ( v24 <= 0x1F )
          _memcpy_fromio((char *)v49 + v23, *(_QWORD *)(a1 + 384), 32 - v23);
      }
      v25 = qrtr_peek_pkt_size(v49);
      v26 = v25;
      v27 = **(unsigned int **)(a1 + 368);
      v28 = **(unsigned int **)(a1 + 360);
      if ( (unsigned int)v25 >= 0x10021 )
      {
        v42 = *(_QWORD *)(a1 + 392);
        if ( (unsigned int)v27 >= (unsigned int)v28 )
          v43 = (unsigned int)(v27 - v28);
        else
          v43 = v27 - v28 + v42;
        if ( v43 > v42 )
        {
          v43 = 0;
          __break(0x800u);
        }
        dev_err(*(_QWORD *)(a1 + 24), "invalid pkt_len:%zu dropping:%zu bytes\n", v25, v43);
        v44 = *(_DWORD **)(a1 + 360);
        v45 = *(_QWORD *)(a1 + 392);
        v46 = (unsigned int)(*v44 + v43);
        if ( v45 <= v46 )
          LODWORD(v46) = (unsigned int)v46 % (unsigned int)v45;
        *v44 = v46;
      }
      else
      {
        v29 = *(_QWORD *)(a1 + 392);
        if ( (unsigned int)v27 >= (unsigned int)v28 )
          v30 = (unsigned int)(v27 - v28);
        else
          v30 = v27 - v28 + v29;
        if ( v30 > v29 )
        {
          __break(0x800u);
          v29 = *(_QWORD *)(a1 + 392);
          v30 = 0;
          LODWORD(v28) = **(_DWORD **)(a1 + 360);
        }
        if ( v30 >= v25 )
          v31 = v25;
        else
          v31 = v30;
        if ( v29 <= (unsigned int)v28 )
          v32 = v29;
        else
          v32 = 0;
        v33 = (unsigned int)(v28 - v32);
        v34 = v29 - v33;
        if ( v29 < v33 )
        {
          __break(0x800u);
        }
        else
        {
          v35 = *(_QWORD *)(a1 + 32);
          if ( v34 >= v31 )
            v36 = v31;
          else
            v36 = v29 - v33;
          if ( v36 )
            _memcpy_fromio(*(_QWORD *)(a1 + 32), *(_QWORD *)(a1 + 384) + v33, v36);
          if ( v34 < v31 )
            _memcpy_fromio(v35 + v36, *(_QWORD *)(a1 + 384), v31 - v36);
        }
        v37 = *(_DWORD **)(a1 + 360);
        v38 = *(_QWORD *)(a1 + 392);
        v39 = (unsigned int)(*v37 + v31);
        if ( v38 <= v39 )
          LODWORD(v39) = (unsigned int)v39 % (unsigned int)v38;
        *v37 = v39;
        if ( v30 >= v26 )
        {
          if ( (unsigned int)qrtr_endpoint_post(a1, *(_QWORD *)(a1 + 32), v26) == -22 )
            dev_err(*(_QWORD *)(a1 + 24), "invalid ipcrouter packet\n");
        }
        else
        {
          *(_QWORD *)(a1 + 40) = v26;
          *(_DWORD *)(a1 + 48) = v31;
        }
      }
    }
    if ( **(_DWORD **)(a1 + 376) )
    {
      v40 = *(_QWORD *)(a1 + 264);
      v49[0] = 1;
      v41 = gh_dbl_send(v40, v49, 0x100000000LL);
      if ( v41 )
      {
        if ( v41 == 11 )
        {
          if ( (*(_BYTE *)(a1 + 176) & 1) == 0 )
            goto LABEL_75;
        }
        else
        {
          dev_err(*(_QWORD *)(a1 + 24), "failed to raise doorbell %d\n", v41);
          if ( (*(_BYTE *)(a1 + 176) & 1) == 0 )
LABEL_75:
            queue_work_on(32, system_wq, a1 + 280);
        }
      }
    }
  }
  __break(0x800u);
LABEL_90:
  result = raw_spin_unlock_irqrestore(a1 + 312, v48);
  _ReadStatusReg(SP_EL0);
  return result;
}
