__int64 __fastcall mhi_sat_connect_worker(__int64 a1)
{
  _QWORD *v2; // x23
  int v3; // w22
  bool v4; // zf
  int v5; // w24
  __int64 v6; // x0
  int v7; // w9
  __int64 v8; // x10
  __int64 v9; // x21
  int v10; // w8
  int v11; // w11
  int v12; // w8
  __int16 v13; // w9
  __int16 v14; // w8
  __int64 v15; // x8
  int v16; // w20
  __int64 result; // x0
  _QWORD v18[2]; // [xsp+0h] [xbp-10h] BYREF

  v18[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD **)(a1 - 112);
  v18[0] = 0;
  raw_spin_lock_irq(a1 + 128);
  if ( !v2[1] || *(_DWORD *)(a1 + 116) != *(_DWORD *)(a1 + 112) || (v3 = *(_DWORD *)(a1 + 124), (v3 | 2) != 2) )
  {
LABEL_23:
    result = raw_spin_unlock_irq(a1 + 128);
    goto LABEL_24;
  }
  *(_DWORD *)(a1 + 124) = 1;
  raw_spin_unlock_irq(a1 + 128);
  v4 = a1 == 136 || v2 == nullptr;
  v5 = !v4;
  if ( v4 )
  {
    if ( (unsigned int)mhi_controller_get_base(*(_QWORD *)(a1 - 120), v18) )
      goto LABEL_21;
  }
  else
  {
    ipc_log_string(
      v2[11],
      "%s[I][%s][%x] Entered\n",
      (const char *)&unk_8360,
      "mhi_sat_connect_worker",
      *(_DWORD *)(a1 + 96));
    if ( (unsigned int)mhi_controller_get_base(*(_QWORD *)(a1 - 120), v18) )
    {
      printk(&unk_861C, "mhi_sat_connect_worker", *v2, *(unsigned int *)(a1 + 96));
      ipc_log_string(
        v2[11],
        "%s[E][%s][%x] Could not get controller base address\n",
        (const char *)&unk_8360,
        "mhi_sat_connect_worker",
        *(_DWORD *)(a1 + 96));
      goto LABEL_21;
    }
  }
  v6 = _kmalloc_cache_noprof(_kmalloc_cache_noprof, 2080, 72);
  if ( !v6 )
  {
LABEL_21:
    raw_spin_lock_irq(a1 + 128);
    if ( *(_DWORD *)(a1 + 124) == 1 )
      *(_DWORD *)(a1 + 124) = v3;
    goto LABEL_23;
  }
  v7 = *(unsigned __int16 *)(a1 + 108);
  v8 = v18[0];
  v9 = v6;
  *(_QWORD *)(v6 + 40) = 0;
  *(_QWORD *)(v6 + 48) = 0x20000002000000LL;
  v11 = *(_DWORD *)(a1 + 96);
  v10 = *(_DWORD *)(a1 + 100);
  *(_QWORD *)(v6 + 24) = v8;
  v12 = v7 | (v10 << 16);
  v13 = *(_WORD *)(a1 + 120);
  *(_DWORD *)(v6 + 32) = v12;
  *(_DWORD *)(v6 + 36) = 7208960;
  *(_QWORD *)(v6 + 56) = 0;
  *(_QWORD *)(v6 + 64) = 0x40000002000000LL;
  if ( v13 == -2 )
    v14 = 0;
  else
    v14 = v13 + 1;
  *(_DWORD *)v6 = 1;
  *(_WORD *)(a1 + 120) = v14;
  *(_WORD *)(v6 + 4) = 14;
  *(_WORD *)(v6 + 6) = v14;
  v15 = *(_QWORD *)(a1 - 112);
  *(_DWORD *)(v6 + 8) = 3211263;
  *(_DWORD *)(v6 + 12) = v11;
  v16 = rpmsg_send(*(_QWORD *)(*(_QWORD *)(v15 + 8) + 968LL), v6, 72);
  result = kfree(v9);
  if ( v16 )
  {
    if ( v5 )
    {
      printk(&unk_8856, "mhi_sat_connect_worker", *v2, *(unsigned int *)(a1 + 96));
      ipc_log_string(
        v2[11],
        "%s[E][%s][%x] Failed to send hello packet:%d\n",
        (const char *)&unk_8360,
        "mhi_sat_connect_worker",
        *(_DWORD *)(a1 + 96),
        v16);
    }
    goto LABEL_21;
  }
  if ( v5 )
    result = ipc_log_string(
               v2[11],
               "%s[I][%s][%x] Device 0x%x sent hello packet\n",
               (const char *)&unk_8360,
               "mhi_sat_connect_worker",
               *(_DWORD *)(a1 + 96),
               *(_DWORD *)(a1 + 96));
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return result;
}
