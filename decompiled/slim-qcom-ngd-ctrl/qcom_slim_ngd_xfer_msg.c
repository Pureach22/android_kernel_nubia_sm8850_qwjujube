__int64 __fastcall qcom_slim_ngd_xfer_msg(__int64 a1, unsigned __int8 *a2)
{
  int v2; // w26
  __int64 v3; // x19
  __int64 result; // x0
  __int64 v5; // x8
  __int64 v6; // x1
  int v7; // w8
  unsigned int v10; // w20
  int v11; // w8
  __int64 v12; // x1
  int v13; // w8
  int v14; // w4
  __int64 v15; // x0
  unsigned int v16; // w8
  __int64 v17; // x9
  __int64 v18; // x22
  int v19; // w10
  int *v20; // x22
  unsigned __int8 *v21; // x1
  int v22; // w28
  int v23; // w8
  bool v24; // zf
  int v25; // w8
  __int64 v26; // x10
  _BYTE *v27; // x0
  int v28; // w8
  __int64 v29; // x8
  __int64 v30; // x1
  int v31; // w8
  int v32; // w9
  unsigned int v33; // w9
  __int64 v34; // x0
  char v35; // w9
  int v36; // w8
  unsigned int v37; // w0
  unsigned int v38; // w20
  __int64 v39; // x1
  int v40; // w8
  __int64 v41; // x10
  unsigned __int8 v42; // w11
  _BYTE *v43; // x8
  unsigned int v44; // w26
  char *v45; // x9
  __int64 v46; // x10
  char *v47; // x9
  char v48; // t1
  char v49; // w9
  unsigned int v50; // w0
  __int64 v51; // x1
  int v52; // w8
  __int64 v53; // x11
  int v54; // w8
  int v55; // w8
  int v56; // w8
  _QWORD v57[5]; // [xsp+8h] [xbp-58h] BYREF
  _QWORD v58[6]; // [xsp+30h] [xbp-30h] BYREF

  v58[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = a2[7];
  v3 = *(_QWORD *)(*(_QWORD *)a1 + 152LL);
  *(_DWORD *)(v3 + 5048) = 0;
  *(_DWORD *)(v3 + 5112) = 0;
  if ( !a2[1] && (a2[2] & 0xE0) == 0x40 )
    goto LABEL_3;
  if ( a2[3] == 1 )
  {
    result = 4294967203LL;
    goto LABEL_116;
  }
  v5 = *((_QWORD *)a2 + 1);
  memset(v58, 0, 40);
  memset(v57, 0, sizeof(v57));
  if ( *(unsigned __int8 *)(v5 + 2) > 0x28u || *a2 >= 0x29u )
  {
    _slimbus_dbg();
    v7 = *(_DWORD *)(v3 + 5476);
    if ( v7 >= 1 )
    {
      printk(&unk_D3E7, v6);
      ipc_log_string(*(_QWORD *)(v3 + 5488), "msg exceeds HW limit\n");
      *(_QWORD *)(v3 + 5472) = *(unsigned int *)(v3 + 5476);
    }
    else if ( v7 )
    {
LABEL_10:
      result = 4294967274LL;
      goto LABEL_116;
    }
    ipc_log_string(*(_QWORD *)(v3 + 5496), "msg exceeds HW limit\n");
    result = 4294967274LL;
    goto LABEL_116;
  }
  if ( !(unsigned int)mutex_trylock(v3 + 5152) )
  {
    _slimbus_dbg();
    v13 = *(_DWORD *)(v3 + 5476);
    if ( v13 >= 1 )
    {
      printk(&unk_CEC4, v12);
      ipc_log_string(*(_QWORD *)(v3 + 5488), "ngd going down due SSR/PDR, try again! skipping check hw state\n");
      *(_QWORD *)(v3 + 5472) = *(unsigned int *)(v3 + 5476);
    }
    else if ( v13 )
    {
      goto LABEL_27;
    }
    ipc_log_string(*(_QWORD *)(v3 + 5496), "ngd going down due SSR/PDR, try again! skipping check hw state\n");
LABEL_75:
    result = 4294967285LL;
    goto LABEL_116;
  }
  v10 = a2[2];
  if ( (v10 != 1 || a2[1] != 6) && *(_DWORD *)(v3 + 5384) == 3 )
  {
    _slimbus_dbg();
    v11 = *(_DWORD *)(v3 + 5476);
    if ( v11 >= 3 )
    {
      ipc_log_string(*(_QWORD *)(v3 + 5488), "ADSP slimbus not up yet MC:0x%x,mt:0x%x\n", v10, a2[1]);
      v11 = *(_DWORD *)(v3 + 5476);
    }
    if ( !v11 )
      ipc_log_string(*(_QWORD *)(v3 + 5496), "ADSP slimbus not up yet MC:0x%x,mt:0x%x\n", v10, a2[1]);
    if ( a2[1] )
    {
      if ( a2[1] == 2 && (v10 <= 0x2E && ((1LL << v10) & 0x401800000000LL) != 0 || v10 - 32 < 0xE) )
      {
LABEL_110:
        v14 = -121;
        goto LABEL_111;
      }
    }
    else
    {
      v14 = -22;
      if ( v10 == 20 || v10 == 36 || v10 == 88 || (v14 = -121, v10 - 16 < 9) || (v10 & 0xE0) == 0x40 )
      {
LABEL_111:
        v38 = v14;
        _slimbus_dbg();
        v56 = *(_DWORD *)(v3 + 5476);
        if ( v56 >= 2 )
        {
          printk(&unk_CA8B, a2[2]);
          ipc_log_string(*(_QWORD *)(v3 + 5488), "ADSP slimbus not up MC:0x%x,mt:0x%x ret:%d\n", a2[2], a2[1], v38);
          if ( *(_DWORD *)(v3 + 5476) )
            goto LABEL_114;
        }
        else if ( v56 )
        {
          goto LABEL_114;
        }
        ipc_log_string(*(_QWORD *)(v3 + 5496), "ADSP slimbus not up MC:0x%x,mt:0x%x ret:%d\n", a2[2], a2[1], v38);
        goto LABEL_114;
      }
    }
    if ( (*(_BYTE *)(v3 + 5481) & 1) != 0 )
    {
      *(_DWORD *)(v3 + 4912) = 0;
      if ( (unsigned int)wait_for_completion_timeout(v3 + 4912, 250) )
        goto LABEL_37;
      _slimbus_dbg();
      v36 = *(_DWORD *)(v3 + 5476);
      if ( v36 >= 2 )
      {
        printk(&unk_D526, v10);
        ipc_log_string(*(_QWORD *)(v3 + 5488), "ADSP slimbus not up timeout MC:0x%x,mt:0x%x\n", v10, a2[1]);
        if ( *(_DWORD *)(v3 + 5476) )
          goto LABEL_79;
      }
      else if ( v36 )
      {
LABEL_79:
        v14 = -121;
        goto LABEL_111;
      }
      ipc_log_string(*(_QWORD *)(v3 + 5496), "ADSP slimbus not up timeout MC:0x%x,mt:0x%x\n", v10, a2[1]);
    }
    else
    {
      _slimbus_dbg();
      v32 = *(_DWORD *)(v3 + 5476);
      if ( v32 >= 3 )
      {
        ipc_log_string(*(_QWORD *)(v3 + 5488), "Not waiting for ADSP up MC:0x%x,mt:0x%x\n", v10, a2[1]);
        v32 = *(_DWORD *)(v3 + 5476);
      }
      if ( !v32 )
        ipc_log_string(*(_QWORD *)(v3 + 5496), "Not waiting for ADSP up MC:0x%x,mt:0x%x\n", v10, a2[1]);
    }
    goto LABEL_110;
  }
LABEL_37:
  v15 = raw_spin_lock_irqsave(v3 + 5144);
  v16 = *(_DWORD *)(v3 + 5424);
  if ( (int)(v16 + 1) % 30 == *(_DWORD *)(v3 + 5428) || (v17 = *(_QWORD *)(v3 + 5416)) == 0 )
  {
    raw_spin_unlock_irqrestore(v3 + 5144, v15);
    goto LABEL_59;
  }
  if ( v16 < 0x1F )
  {
    v18 = v3 + 48LL * v16;
    *(_QWORD *)(v18 + 3456) = v3 + 5112;
    v19 = *(_DWORD *)(v3 + 5424) + 1;
    *(_QWORD *)(v18 + 3480) = v17 + 40 * v16;
    *(_DWORD *)(v3 + 5424) = v19 % 30;
    raw_spin_unlock_irqrestore(v3 + 5144, v15);
    v20 = *(int **)(v18 + 3480);
    if ( v20 )
    {
      mutex_unlock(v3 + 5152);
      v21 = a2;
      if ( a2[1] )
      {
        v22 = 0;
LABEL_43:
        --*v21;
        *v20 = 0;
        v23 = *v21 | (32 * v21[1]) | (v21[2] << 8) | (v2 << 16);
        v24 = v21[3] == 0;
        if ( v21[3] )
          v23 |= 0x8000u;
        *v20 = v23;
        v25 = v21[1];
        if ( v24 )
          v26 = 3;
        else
          v26 = 2;
        v27 = (char *)v20 + v26;
        if ( !((v21[2] - 32) & 0xBE | v25) )
        {
          *v27++ = v21[6];
          v25 = v21[1];
        }
        if ( !v25 )
        {
          v28 = v21[2];
          if ( (unsigned int)(v28 - 32) < 0xA || (unsigned int)(v28 - 96) <= 8 )
          {
            *v27 = v21[4];
            v27[1] = v21[5];
            v27 += 2;
          }
        }
        v29 = *((_QWORD *)v21 + 1);
        if ( v29 && *(_QWORD *)(v29 + 16) )
        {
          if ( *(_BYTE *)(v3 + 5468) == 1 )
            _memcpy_toio(v27);
          else
            memcpy(v27, *(const void **)(*((_QWORD *)a2 + 1) + 16LL), *(unsigned __int8 *)(v29 + 2));
        }
        if ( (unsigned int)mutex_trylock(v3 + 5152) )
        {
          v37 = qcom_slim_ngd_tx_msg_post(v3, v20, *a2);
          if ( v37 )
          {
            v38 = v37;
LABEL_114:
            mutex_unlock(v3 + 5152);
            goto LABEL_115;
          }
          if ( (unsigned int)wait_for_completion_timeout(v3 + 5112, 500) )
          {
            if ( !v22 || (unsigned int)wait_for_completion_timeout(v3 + 5048, 250) )
            {
              mutex_unlock(v3 + 5152);
LABEL_3:
              result = 0;
LABEL_116:
              _ReadStatusReg(SP_EL0);
              return result;
            }
            _slimbus_dbg();
            v55 = *(_DWORD *)(v3 + 5476);
            if ( v55 >= 2 )
            {
              printk(&unk_D4FF, a2[2]);
              ipc_log_string(*(_QWORD *)(v3 + 5488), "TX usr_msg timed out:MC:0x%x,mt:0x%x", a2[2], a2[1]);
              if ( *(_DWORD *)(v3 + 5476) )
                goto LABEL_106;
            }
            else if ( v55 )
            {
LABEL_106:
              *(_BYTE *)(v3 + 5509) = 1;
              *((_QWORD *)a2 + 2) = 0;
              mutex_unlock(v3 + 5152);
              result = 4294967186LL;
              goto LABEL_116;
            }
            ipc_log_string(*(_QWORD *)(v3 + 5496), "TX usr_msg timed out:MC:0x%x,mt:0x%x", a2[2], a2[1]);
            goto LABEL_106;
          }
          _slimbus_dbg();
          v54 = *(_DWORD *)(v3 + 5476);
          if ( v54 >= 2 )
          {
            printk(&unk_C9E3, a2[2]);
            ipc_log_string(*(_QWORD *)(v3 + 5488), "TX timed out:MC:0x%x,mt:0x%x", a2[2], a2[1]);
            if ( *(_DWORD *)(v3 + 5476) )
              goto LABEL_102;
          }
          else if ( v54 )
          {
LABEL_102:
            mutex_unlock(v3 + 5152);
            result = 4294967186LL;
            *(_BYTE *)(v3 + 5509) = 1;
            goto LABEL_116;
          }
          ipc_log_string(*(_QWORD *)(v3 + 5496), "TX timed out:MC:0x%x,mt:0x%x", a2[2], a2[1]);
          goto LABEL_102;
        }
        _slimbus_dbg();
        v40 = *(_DWORD *)(v3 + 5476);
        if ( v40 >= 1 )
        {
          printk(&unk_C69A, v39);
          ipc_log_string(*(_QWORD *)(v3 + 5488), "ngd going down due SSR/PDR, try again! skipping tx msg post\n");
          *(_QWORD *)(v3 + 5472) = *(unsigned int *)(v3 + 5476);
          goto LABEL_86;
        }
        if ( !v40 )
        {
LABEL_86:
          ipc_log_string(*(_QWORD *)(v3 + 5496), "ngd going down due SSR/PDR, try again! skipping tx msg post\n");
          goto LABEL_75;
        }
LABEL_27:
        result = 4294967285LL;
        goto LABEL_116;
      }
      v33 = a2[2];
      v22 = 0;
      if ( v33 > 0x14 || ((1 << v33) & 0x130000) == 0 )
        goto LABEL_43;
      a2[1] = 2;
      if ( v33 == 16 )
      {
        v35 = 44;
        v34 = a1;
      }
      else
      {
        v34 = a1;
        if ( v33 == 20 )
        {
          v41 = *((_QWORD *)a2 + 1);
          v42 = a2[7];
          a2[2] = 46;
          v43 = (char *)v58 + 1;
          v44 = 2;
          v45 = *(char **)(v41 + 16);
          LOBYTE(v58[0]) = v42;
          goto LABEL_94;
        }
        if ( v33 != 17 )
          goto LABEL_10;
        v35 = 45;
      }
      v46 = *((_QWORD *)a2 + 1);
      a2[2] = v35;
      v43 = (char *)v58 + 2;
      v44 = 3;
      v47 = *(char **)(v46 + 16);
      LOBYTE(v58[0]) = a2[7];
      v48 = *v47;
      v45 = v47 + 1;
      BYTE1(v58[0]) = v48;
LABEL_94:
      v49 = *v45;
      *((_QWORD *)a2 + 2) = v3 + 5048;
      *v43 = v49;
      v50 = slim_alloc_txn_tid(v34, a2);
      if ( !v50 )
      {
        v53 = *((_QWORD *)a2 + 1);
        v21 = a2;
        *(_BYTE *)((unsigned __int64)v58 | v44) = a2[6];
        *(_BYTE *)(v53 + 2) = v44 + 1;
        v2 = 255;
        v22 = 1;
        *(_QWORD *)(*((_QWORD *)a2 + 1) + 16LL) = v58;
        *(_QWORD *)(*((_QWORD *)a2 + 1) + 8LL) = v57;
        *a2 = *(_BYTE *)(*((_QWORD *)a2 + 1) + 2LL) + 4;
        goto LABEL_43;
      }
      v38 = v50;
      _slimbus_dbg();
      v52 = *(_DWORD *)(v3 + 5476);
      if ( v52 >= 1 )
      {
        printk(&unk_C9C9, v51);
        ipc_log_string(*(_QWORD *)(v3 + 5488), "Unable to allocate TID\n");
        *(_QWORD *)(v3 + 5472) = *(unsigned int *)(v3 + 5476);
      }
      else if ( v52 )
      {
LABEL_115:
        result = v38;
        goto LABEL_116;
      }
      ipc_log_string(*(_QWORD *)(v3 + 5496), "Unable to allocate TID\n");
      goto LABEL_115;
    }
LABEL_59:
    _slimbus_dbg();
    v31 = *(_DWORD *)(v3 + 5476);
    if ( v31 >= 1 )
    {
      printk(&unk_C5A6, v30);
      ipc_log_string(*(_QWORD *)(v3 + 5488), "Message buffer unavailable\n");
      *(_QWORD *)(v3 + 5472) = *(unsigned int *)(v3 + 5476);
    }
    else if ( v31 )
    {
LABEL_62:
      mutex_unlock(v3 + 5152);
      result = 4294967284LL;
      goto LABEL_116;
    }
    ipc_log_string(*(_QWORD *)(v3 + 5496), "Message buffer unavailable\n");
    goto LABEL_62;
  }
  __break(0x5512u);
  return slim_pd_status(v15, v15);
}
