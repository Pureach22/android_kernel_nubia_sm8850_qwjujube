__int64 __fastcall dwc3_msm_ep_enable(__int64 a1, __int64 a2)
{
  unsigned int v2; // w20
  __int64 v3; // x22
  int v4; // w9
  __int64 v5; // x23
  __int64 v6; // x9
  __int64 v8; // x0
  __int64 v9; // x26
  __int64 v10; // x19
  __int64 v11; // x25
  __int64 v12; // x8
  __int64 v13; // x24
  __int64 v14; // x20
  int v15; // w21
  __int64 v16; // x8
  int v17; // w9
  int v18; // w0
  void *v19; // x0
  _DWORD *v20; // x9
  int v21; // w11
  __int64 v24; // x0
  const char *v25; // x0
  const char **v26; // x8
  const char *v27; // x2
  __int64 v28; // [xsp+8h] [xbp-18h] BYREF
  int v29; // [xsp+10h] [xbp-10h]
  __int64 v30; // [xsp+18h] [xbp-8h]

  v2 = -22;
  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 && a2 && *(_BYTE *)(a2 + 1) == 5 && *(_WORD *)(a2 + 4) )
  {
    v3 = *(_QWORD *)(a1 + 152);
    v4 = *(_DWORD *)(a1 + 164);
    v5 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v3 + 368) + 96LL) + 152LL);
    if ( (v4 & 1) != 0 && (dwc3_msm_ep_enable___already_done & 1) == 0 )
    {
      v24 = *(_QWORD *)(v3 + 368);
      dwc3_msm_ep_enable___already_done = 1;
      v25 = (const char *)dev_driver_string(v24);
      v26 = *(const char ***)(v3 + 368);
      v27 = v26[14];
      if ( !v27 )
        v27 = *v26;
      _warn_printk("%s %s: %s is already enabled\n", v25, v27, (const char *)(a1 + 184));
      v2 = 0;
      __break(0x800u);
    }
    else if ( (v4 & 1) != 0 )
    {
      v2 = 0;
    }
    else
    {
      v6 = *(_QWORD *)(v3 + 376);
      if ( *(_DWORD *)(v6 + 500) == 2 && (*(_WORD *)(v6 + 488) & 7) == 0 )
      {
        dev_err(*(_QWORD *)(v3 + 368), "fail ep_enable %s device is into LPM\n", (const char *)(a1 + 184));
      }
      else
      {
        v8 = raw_spin_lock_irqsave(v3 + 312);
        v9 = *(_QWORD *)(a1 + 152);
        v10 = v8;
        v11 = *(_QWORD *)(a1 + 24);
        v29 = 0;
        v12 = *(_QWORD *)(v9 + 368);
        v28 = 0;
        v13 = *(_QWORD *)(*(_QWORD *)(v12 + 96) + 152LL);
        dwc3_msm_depcfg_params(a1, &v28);
        v14 = a1;
        v15 = dwc3_core_send_gadget_ep_cmd(a1, 1, &v28);
        if ( v15 )
        {
          dev_err(*(_QWORD *)(v9 + 368), "set_ep_config() failed for %s\n", (const char *)(v14 + 184));
          v16 = v14;
        }
        else
        {
          v16 = v14;
          if ( (*(_BYTE *)(v14 + 164) & 1) == 0 )
          {
            dwc3_core_resize_tx_fifos(v14);
            v17 = *(_DWORD *)(v14 + 164) | 1;
            *(_BYTE *)(v14 + 171) = *(_BYTE *)(v11 + 3) & 3;
            *(_DWORD *)(v14 + 164) = v17;
            v18 = readl(*(_QWORD *)(v13 + 8) + 50976LL);
            writel(v18 | (unsigned int)(1LL << *(_BYTE *)(v14 + 170)), *(_QWORD *)(v13 + 8) + 50976LL);
            v19 = *(void **)(v14 + 136);
            *(_WORD *)(v14 + 168) = 0;
            memset(v19, 0, 0x1000u);
            v20 = *(_DWORD **)(v14 + 136);
            v16 = v14;
            v20[1020] = *(_QWORD *)(v14 + 144);
            v21 = v20[1023] | 0x81;
            v20[1021] = ((unsigned __int64)(unsigned int)((_DWORD)v20 - *(_DWORD *)(v14 + 136)) + *(_QWORD *)(v14 + 144)) >> 32;
            v20[1023] = v21;
          }
        }
        v2 = v15;
        dwc3_dbg_print(*(_QWORD *)(v5 + 1256), *(_BYTE *)(v16 + 170), "ENABLE", v15, (const char *)&unk_16A05);
        raw_spin_unlock_irqrestore(v3 + 312, v10);
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return v2;
}
