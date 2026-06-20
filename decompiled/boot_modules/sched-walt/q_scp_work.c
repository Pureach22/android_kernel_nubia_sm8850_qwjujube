__int64 __fastcall q_scp_work(__int64 result, __int64 a2)
{
  _DWORD *v2; // x8
  _BYTE *v3; // x9
  int v4; // w9
  int v5; // w8
  int v7; // w9
  __int64 v8; // x19

  v2 = (_DWORD *)(a2 + 5184);
  if ( (_UNKNOWN *)a2 == &init_task )
    v2 = &vendor_data_pad;
  if ( *((_BYTE *)v2 + 456) == 1 )
  {
    v3 = (_UNKNOWN *)result == &init_task ? &vendor_data_pad : (_BYTE *)(result + 5184);
    if ( v3[456] == 1 )
    {
      v4 = *(_DWORD *)(a2 + 1804);
      if ( v4 == *(_DWORD *)(result + 1804) )
      {
        if ( scp_udata && scp_udata == v4 )
        {
          if ( qword_6A5A0 )
          {
            if ( qword_6A5A0 == *((_QWORD *)v2 + 61) )
            {
              v5 = v2[120];
              if ( v5 == 2 || v5 == 1 && (unsigned int)(*(_DWORD *)(a2 + 1352) - 3) >= 0xFFFFFFFE )
                return result;
            }
          }
        }
        else if ( (v2[120] | 2) != 3 )
        {
          return result;
        }
        result = _kmalloc_cache_noprof(android_rvh_probe_register, 3520, 48);
        if ( result )
        {
          v7 = (unsigned __int8)kthread_running;
          *(_DWORD *)result = *(_DWORD *)(a2 + 1800);
          if ( v7 == 1 )
          {
            *(_QWORD *)(result + 32) = 0;
            *(_QWORD *)(result + 40) = 0;
            v8 = result;
            *(_QWORD *)(result + 8) = result + 8;
            *(_QWORD *)(result + 16) = result + 8;
            *(_QWORD *)(result + 24) = scp_work;
            result = kthread_queue_work(&worker, result + 8);
            if ( (result & 1) == 0 )
            {
              if ( byte_6A5A8 == 1 )
                printk(&unk_63A1C);
              result = kfree(v8);
            }
            if ( byte_6A5A8 == 1 )
              return printk(&unk_66D7E);
          }
          else
          {
            return kfree(result);
          }
        }
        else if ( byte_6A5A8 == 1 )
        {
          return printk(&unk_66D44);
        }
      }
    }
  }
  return result;
}
