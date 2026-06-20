__int64 __fastcall pld_unregister_driver(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x19
  __int64 result; // x0

  v4 = pld_ctx;
  if ( !pld_ctx )
    return printk(&unk_985BB0, "pld_unregister_driver", 346, a4);
  if ( !*(_QWORD *)pld_ctx )
    return printk(&unk_AA399F, "pld_unregister_driver", 351, a4);
  result = pld_pcie_unregister_driver();
  *(_DWORD *)(v4 + 32) = 0;
  *(_QWORD *)v4 = 0;
  return result;
}
