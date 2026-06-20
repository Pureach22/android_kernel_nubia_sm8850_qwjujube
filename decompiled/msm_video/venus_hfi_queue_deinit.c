__int64 __fastcall venus_hfi_queue_deinit(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x8
  __int64 (__fastcall *v3)(__int64, __int64); // x9
  __int64 (__fastcall *v4)(__int64, __int64); // x9
  __int64 (__fastcall *v5)(__int64, __int64); // x9
  __int64 (__fastcall *v6)(__int64, __int64); // x9
  __int64 (__fastcall *v7)(__int64, __int64); // x9
  __int64 (__fastcall *v8)(__int64, __int64); // x8
  __int64 v9; // x8
  __int64 (__fastcall *v10)(__int64, __int64); // x8

  v1 = result;
  if ( (msm_vidc_debug & 2) != 0 )
  {
    result = printk(&unk_83C01, "high", 0xFFFFFFFFLL, "codec", "venus_hfi_queue_deinit");
    if ( *(_QWORD *)(v1 + 4944) )
      goto LABEL_3;
  }
  else if ( *(_QWORD *)(result + 4944) )
  {
LABEL_3:
    if ( v1 )
    {
      v2 = *(_QWORD *)(v1 + 6568);
      if ( v2 )
      {
        v3 = *(__int64 (__fastcall **)(__int64, __int64))(v2 + 64);
        if ( !v3 )
          goto LABEL_9;
        if ( *((_DWORD *)v3 - 1) != 481270700 )
          __break(0x8229u);
        result = v3(v1, v1 + 4960);
        v2 = *(_QWORD *)(v1 + 6568);
        if ( v2 )
        {
LABEL_9:
          v4 = *(__int64 (__fastcall **)(__int64, __int64))(v2 + 64);
          if ( !v4 )
            goto LABEL_13;
          if ( *((_DWORD *)v4 - 1) != 481270700 )
            __break(0x8229u);
          result = v4(v1, v1 + 4816);
          v2 = *(_QWORD *)(v1 + 6568);
          if ( v2 )
          {
LABEL_13:
            v5 = *(__int64 (__fastcall **)(__int64, __int64))(v2 + 104);
            if ( !v5 )
              goto LABEL_17;
            if ( *((_DWORD *)v5 - 1) != 481270700 )
              __break(0x8229u);
            result = v5(v1, v1 + 5248);
            v2 = *(_QWORD *)(v1 + 6568);
            if ( v2 )
            {
LABEL_17:
              v6 = *(__int64 (__fastcall **)(__int64, __int64))(v2 + 104);
              if ( !v6 )
                goto LABEL_21;
              if ( *((_DWORD *)v6 - 1) != 481270700 )
                __break(0x8229u);
              result = v6(v1, v1 + 5392);
              v2 = *(_QWORD *)(v1 + 6568);
              if ( v2 )
              {
LABEL_21:
                v7 = *(__int64 (__fastcall **)(__int64, __int64))(v2 + 104);
                if ( !v7 )
                  goto LABEL_25;
                if ( *((_DWORD *)v7 - 1) != 481270700 )
                  __break(0x8229u);
                result = v7(v1, v1 + 5536);
                v2 = *(_QWORD *)(v1 + 6568);
                if ( v2 )
                {
LABEL_25:
                  v8 = *(__int64 (__fastcall **)(__int64, __int64))(v2 + 64);
                  if ( v8 )
                  {
                    if ( *((_DWORD *)v8 - 1) != 481270700 )
                      __break(0x8228u);
                    result = v8(v1, v1 + 5104);
                  }
                }
              }
            }
          }
        }
      }
      if ( *(_QWORD *)(v1 + 4624) )
      {
        v9 = *(_QWORD *)(v1 + 6568);
        if ( v9 )
        {
          v10 = *(__int64 (__fastcall **)(__int64, __int64))(v9 + 80);
          if ( v10 )
          {
            if ( *((_DWORD *)v10 - 1) != 481270700 )
              __break(0x8228u);
            result = v10(v1, v1 + 6640);
          }
        }
      }
    }
    *(_QWORD *)(v1 + 5656) = 0;
    *(_QWORD *)(v1 + 5672) = 0;
    *(_DWORD *)(v1 + 5664) = 0;
    *(_QWORD *)(v1 + 5808) = 0;
    *(_QWORD *)(v1 + 5824) = 0;
    *(_DWORD *)(v1 + 5816) = 0;
    *(_QWORD *)(v1 + 5960) = 0;
    *(_QWORD *)(v1 + 5976) = 0;
    *(_DWORD *)(v1 + 5968) = 0;
    *(_QWORD *)(v1 + 4944) = 0;
    *(_DWORD *)(v1 + 4936) = 0;
    *(_QWORD *)(v1 + 4800) = 0;
    *(_DWORD *)(v1 + 4792) = 0;
    *(_QWORD *)(v1 + 5232) = 0;
    *(_DWORD *)(v1 + 5224) = 0;
    *(_QWORD *)(v1 + 5376) = 0;
    *(_DWORD *)(v1 + 5368) = 0;
    *(_QWORD *)(v1 + 5520) = 0;
    *(_DWORD *)(v1 + 5512) = 0;
    *(_QWORD *)(v1 + 5088) = 0;
    *(_DWORD *)(v1 + 5080) = 0;
    return result;
  }
  if ( (msm_vidc_debug & 2) != 0 )
    return printk(&unk_8A194, "high", 0xFFFFFFFFLL, "codec", "venus_hfi_queue_deinit");
  return result;
}
