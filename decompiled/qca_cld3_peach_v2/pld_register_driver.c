__int64 __fastcall pld_register_driver(_QWORD *a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x19
  __int64 result; // x0
  __int64 v6; // x3
  __int64 v7; // x21
  unsigned int v8; // w22

  v4 = pld_ctx;
  if ( pld_ctx )
  {
    if ( *(_QWORD *)pld_ctx )
    {
      printk(&unk_9794BB, "pld_register_driver", 254, a4);
      return 4294967279LL;
    }
    else if ( a1 && *a1 && a1[1] && a1[7] && a1[8] )
    {
      *(_QWORD *)pld_ctx = a1;
      *(_DWORD *)(v4 + 32) = 0;
      result = pld_pcie_register_driver();
      if ( (_DWORD)result )
      {
        v7 = jiffies;
        if ( pld_register_driver___last_ticks - jiffies + 1500 < 0 )
        {
          v8 = result;
          printk(&unk_9922C5, "pld_register_driver", 271, v6);
          result = v8;
          pld_register_driver___last_ticks = v7;
        }
        *(_DWORD *)(v4 + 32) = 0;
        *(_QWORD *)v4 = 0;
      }
      else
      {
        *(_DWORD *)(v4 + 32) |= 0x7Fu;
      }
    }
    else
    {
      printk(&unk_9794E9, "pld_register_driver", 261, a4);
      return 4294967274LL;
    }
  }
  else
  {
    printk(&unk_985BB0, "pld_register_driver", 248, a4);
    return 4294967277LL;
  }
  return result;
}
