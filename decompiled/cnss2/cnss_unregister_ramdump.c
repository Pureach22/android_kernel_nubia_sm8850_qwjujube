_QWORD *__fastcall cnss_unregister_ramdump(
        _QWORD *result,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // x6
  _QWORD *v9; // x19
  __int64 v11; // x2
  unsigned __int64 StatusReg; // x8
  const char *v13; // x1
  __int16 v14; // w9
  const char *v15; // x8
  char v16; // [xsp+0h] [xbp+0h]

  v8 = result[66];
  v9 = result;
  if ( (unsigned __int64)(v8 - 4352) > 0x12 || ((1LL << v8) & 0x6448F) == 0 )
  {
    if ( v8 == 62 )
    {
      v11 = result[22];
      if ( v11 )
        return (_QWORD *)dma_free_attrs(*result + 16LL, result[21], v11, result[23], 0);
    }
    else
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
      {
        v13 = "irq";
      }
      else
      {
        v14 = *(_DWORD *)(StatusReg + 16);
        v15 = (const char *)(StatusReg + 2320);
        if ( (v14 & 0xFF00) != 0 )
          v13 = "soft_irq";
        else
          v13 = v15;
      }
      return (_QWORD *)cnss_debug_ipc_log_print(
                         cnss_ipc_log_context,
                         v13,
                         "cnss_unregister_ramdump",
                         3u,
                         3u,
                         "Unknown device ID: 0x%lx\n",
                         v8,
                         a8,
                         v16);
    }
  }
  else
  {
    result = (_QWORD *)kfree(result[34]);
    v9[34] = 0;
    *((_BYTE *)v9 + 280) = 0;
  }
  return result;
}
