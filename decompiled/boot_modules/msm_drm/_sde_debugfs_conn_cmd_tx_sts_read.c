__int64 __fastcall sde_debugfs_conn_cmd_tx_sts_read(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, __int64 *a4)
{
  __int64 v4; // x20
  __int64 v5; // x8
  __int64 v6; // x23
  int v10; // w20
  unsigned int v11; // w8
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v13; // x9
  __int64 v14; // x0
  unsigned __int64 v15; // x9
  unsigned __int64 v21; // x8
  unsigned __int64 v22; // x8
  unsigned __int64 v24; // x9
  char s[8]; // [xsp+8h] [xbp-108h] BYREF
  __int64 v27; // [xsp+10h] [xbp-100h]
  __int64 v28; // [xsp+18h] [xbp-F8h]
  __int64 v29; // [xsp+20h] [xbp-F0h]
  __int64 v30; // [xsp+28h] [xbp-E8h]
  __int64 v31; // [xsp+30h] [xbp-E0h]
  __int64 v32; // [xsp+38h] [xbp-D8h]
  __int64 v33; // [xsp+40h] [xbp-D0h]
  __int64 v34; // [xsp+48h] [xbp-C8h]
  __int64 v35; // [xsp+50h] [xbp-C0h]
  __int64 v36; // [xsp+58h] [xbp-B8h]
  __int64 v37; // [xsp+60h] [xbp-B0h]
  __int64 v38; // [xsp+68h] [xbp-A8h]
  __int64 v39; // [xsp+70h] [xbp-A0h]
  __int64 v40; // [xsp+78h] [xbp-98h]
  __int64 v41; // [xsp+80h] [xbp-90h]
  __int64 v42; // [xsp+88h] [xbp-88h]
  __int64 v43; // [xsp+90h] [xbp-80h]
  __int64 v44; // [xsp+98h] [xbp-78h]
  __int64 v45; // [xsp+A0h] [xbp-70h]
  __int64 v46; // [xsp+A8h] [xbp-68h]
  __int64 v47; // [xsp+B0h] [xbp-60h]
  __int64 v48; // [xsp+B8h] [xbp-58h]
  __int64 v49; // [xsp+C0h] [xbp-50h]
  __int64 v50; // [xsp+C8h] [xbp-48h]
  __int64 v51; // [xsp+D0h] [xbp-40h]
  __int64 v52; // [xsp+D8h] [xbp-38h]
  __int64 v53; // [xsp+E0h] [xbp-30h]
  __int64 v54; // [xsp+E8h] [xbp-28h]
  __int64 v55; // [xsp+F0h] [xbp-20h]
  __int64 v56; // [xsp+F8h] [xbp-18h]
  __int64 v57; // [xsp+100h] [xbp-10h]
  __int64 v58; // [xsp+108h] [xbp-8h]

  v4 = 0;
  v58 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *a4;
  v6 = *(_QWORD *)(a1 + 32);
  v56 = 0;
  v57 = 0;
  v54 = 0;
  v55 = 0;
  v52 = 0;
  v53 = 0;
  v50 = 0;
  v51 = 0;
  v48 = 0;
  v49 = 0;
  v46 = 0;
  v47 = 0;
  v44 = 0;
  v45 = 0;
  v42 = 0;
  v43 = 0;
  v40 = 0;
  v41 = 0;
  v38 = 0;
  v39 = 0;
  v36 = 0;
  v37 = 0;
  v34 = 0;
  v35 = 0;
  v32 = 0;
  v33 = 0;
  v30 = 0;
  v31 = 0;
  v28 = 0;
  v29 = 0;
  *(_QWORD *)s = 0;
  v27 = 0;
  if ( !v5 )
  {
    if ( v6 )
    {
      mutex_lock(v6 + 2816);
      v10 = snprintf(s, 0x100u, "last_cmd_tx_sts:0x%x", *(unsigned __int8 *)(v6 + 4745));
      mutex_unlock(v6 + 2816);
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "output: %s\n", s);
      if ( v10 <= 0 )
      {
        printk(&unk_23FAC0, "_sde_debugfs_conn_cmd_tx_sts_read");
        v4 = -22;
      }
      else
      {
        if ( (unsigned int)v10 <= a3 )
          v11 = v10;
        else
          v11 = a3;
        if ( v11 >= 0x100 )
          v4 = 256;
        else
          v4 = v11;
        _check_object_size(s, v4, 1);
        StatusReg = _ReadStatusReg(SP_EL0);
        if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v13 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
          v13 = a2 & ((__int64)(a2 << 8) >> 8);
        v14 = v4;
        if ( 0x8000000000LL - v4 >= v13 )
        {
          v15 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v21 = *(_QWORD *)(StatusReg + 8);
          _WriteStatusReg(TTBR1_EL1, v21 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
          _WriteStatusReg(TTBR0_EL1, v21);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v15);
          v14 = _arch_copy_to_user(a2 & 0xFF7FFFFFFFFFFFFFLL);
          v22 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v24 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
          _WriteStatusReg(TTBR0_EL1, v24 - 4096);
          _WriteStatusReg(TTBR1_EL1, v24);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v22);
        }
        if ( v14 )
        {
          printk(&unk_2165E3, "_sde_debugfs_conn_cmd_tx_sts_read");
          v4 = -14;
        }
        else
        {
          *a4 += v4;
        }
      }
    }
    else
    {
      printk(&unk_250682, "_sde_debugfs_conn_cmd_tx_sts_read");
      v4 = -22;
    }
  }
  _ReadStatusReg(SP_EL0);
  return v4;
}
