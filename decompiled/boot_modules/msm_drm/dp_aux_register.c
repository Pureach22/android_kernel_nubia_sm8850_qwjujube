__int64 __fastcall dp_aux_register(__int64 a1, __int64 a2)
{
  __int64 v2; // x20
  __int64 v3; // x8
  int v5; // w0
  __int64 v6; // x8
  __int64 v8; // x8
  unsigned int v9; // w19

  if ( a1 )
  {
    *(_QWORD *)(a1 + 224) = "sde_dp_aux";
    v2 = a1 + 224;
    v3 = *(_QWORD *)(a1 - 8);
    *(_QWORD *)(a1 + 1584) = dp_aux_transfer;
    *(_QWORD *)(a1 + 1480) = a2;
    *(_QWORD *)(a1 + 1472) = v3;
    *(_DWORD *)(a1 + 1832) = 1;
    v5 = drm_dp_aux_register(a1 + 224);
    if ( v5 )
    {
      v8 = *(_QWORD *)(a1 + 16);
      v9 = v5;
      ipc_log_string(
        v8,
        "[e][%-4d]%s: failed to register drm aux: %d\n",
        *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
        "dp_aux_register",
        v5);
      printk(&unk_21C06E, "dp_aux_register");
      return v9;
    }
    else
    {
      v6 = *(_QWORD *)(a1 + 1784);
      *(_QWORD *)(a1 + 24) = v2;
      if ( v6 && *(_QWORD *)(v6 + 56) )
      {
        *(_QWORD *)(a1 + 1584) = dp_aux_bridge_transfer;
        return 0;
      }
      else
      {
        return 0;
      }
    }
  }
  else
  {
    _ReadStatusReg(SP_EL0);
    printk(&unk_275B6D, "dp_aux_register");
    return 4294967274LL;
  }
}
