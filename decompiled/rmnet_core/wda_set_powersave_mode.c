__int64 __fastcall wda_set_powersave_mode(_QWORD *a1, char a2, unsigned __int8 a3, const void *a4)
{
  __int64 v8; // x20
  _WORD *v9; // x22
  unsigned int v10; // w0
  unsigned int v11; // w23
  void *v12; // x0
  _QWORD v14[10]; // [xsp+0h] [xbp-50h] BYREF

  v14[9] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 && *a1 )
  {
    memset(v14, 0, 72);
    v8 = _kmalloc_cache_noprof(_stack_chk_fail, 2336, 39);
    if ( v8 )
    {
      v9 = (_WORD *)_kmalloc_cache_noprof(synchronize_rcu, 2336, 4);
      if ( !v9 )
      {
        v11 = -12;
        goto LABEL_23;
      }
      v10 = qmi_txn_init(a1 + 6, v14, &wda_set_powersave_mode_resp_msg_v01_ei, v9);
      if ( (v10 & 0x80000000) != 0 )
      {
        v11 = v10;
        v12 = &unk_2D786;
      }
      else
      {
        *(_BYTE *)v8 = a2;
        if ( a3 <= 0x20u && a2 && a3 && a4 )
        {
          *(_WORD *)(v8 + 1) = 257;
          *(_BYTE *)(v8 + 3) = 1;
          *(_BYTE *)(v8 + 4) = a3;
          memcpy((void *)(v8 + 5), a4, a3);
          *(_WORD *)(v8 + 37) = 257;
        }
        v11 = qmi_send_request(a1 + 6, a1 + 44, v14, 46, 48, &wda_set_powersave_mode_req_msg_v01_ei, v8);
        if ( (v11 & 0x80000000) != 0 )
        {
          qmi_txn_cancel(v14);
          v12 = &unk_2CDDC;
        }
        else
        {
          v11 = qmi_txn_wait(v14, 250);
          if ( (v11 & 0x80000000) == 0 )
          {
            if ( *v9 )
            {
              printk(&unk_2D31A, "wda_set_powersave_mode_req");
              v11 = -(unsigned __int16)*v9;
            }
            goto LABEL_15;
          }
          v12 = &unk_2D7B0;
        }
      }
      printk(v12, "wda_set_powersave_mode_req");
LABEL_15:
      kfree(v9);
LABEL_23:
      kfree(v8);
      goto LABEL_24;
    }
    v11 = -12;
  }
  else
  {
    v11 = -22;
  }
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return v11;
}
