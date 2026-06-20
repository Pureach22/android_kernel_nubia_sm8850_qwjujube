__int64 __fastcall hfi_dbg_dump_reg_read(__int64 a1, __int64 a2, unsigned __int64 a3, _QWORD *a4)
{
  __int64 result; // x0
  __int64 v5; // x20
  __int64 v6; // x21
  unsigned int v7; // w9
  __int64 v8; // x25
  bool v9; // w27
  unsigned __int64 v10; // x22
  __int64 v11; // x20
  __int64 v12; // x21
  int v13; // w0
  __int64 v14; // x8
  __int64 v15; // x23
  __int64 v16; // x21
  int v17; // w5

  if ( *(_QWORD *)(a1 + 32) )
  {
    result = 0;
    if ( a2 && a4 )
    {
      v5 = *(_QWORD *)(hfi_dbg + 48);
      if ( !v5 )
        return 0;
      v6 = *(unsigned int *)(hfi_dbg + 376);
      v7 = *(_DWORD *)(hfi_dbg + 56);
      result = 0;
      v8 = v7 - (unsigned int)v6 >= a3 ? a3 : v7 - (unsigned int)v6;
      if ( v7 > (unsigned int)v6 && v5 + v6 )
      {
        mutex_lock(hfi_dbg + 272);
        if ( v8 )
        {
          v10 = 0;
          v11 = v6 + v5 + 4;
          v12 = 0x400000000LL;
          do
          {
            v13 = scnprintf(*(_QWORD *)(hfi_dbg + 384) + v10, 4096 - v10, " %08x", *(_DWORD *)(v11 - 4));
            v14 = v12 >> 32;
            v10 += v13;
            v9 = v12 >> 32 < v8;
            if ( !v11 )
              break;
            v12 += 0x400000000LL;
            v11 += 4;
          }
          while ( v14 < v8 );
          mutex_unlock(hfi_dbg + 272);
          if ( v10 > a3 )
          {
            printk(&unk_26C305, "hfi_dbg_dump_reg_read");
            return -22;
          }
        }
        else
        {
          mutex_unlock(hfi_dbg + 272);
          v9 = 0;
          v10 = 0;
        }
        if ( v10 >> 31 )
        {
          __break(0x800u);
          v16 = -14;
        }
        else
        {
          v15 = *(_QWORD *)(hfi_dbg + 384);
          _check_object_size(v15, v10, 1);
          if ( inline_copy_to_user_0(a2, v15, v10) )
            v16 = -14;
          else
            v16 = v10;
        }
        *a4 += v16;
        if ( v9 )
          v17 = *(_DWORD *)(hfi_dbg + 56);
        else
          v17 = *(_DWORD *)(hfi_dbg + 376) + v8;
        *(_DWORD *)(hfi_dbg + 376) = v17;
        printk(&unk_223DEC, "hfi_dbg_dump_reg_read");
        return v16;
      }
    }
  }
  else
  {
    printk(&unk_21D21A, "hfi_dbg_dump_reg_read");
    return -19;
  }
  return result;
}
