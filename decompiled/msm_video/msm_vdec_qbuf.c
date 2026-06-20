__int64 __fastcall msm_vdec_qbuf(__int64 a1, __int64 a2)
{
  __int64 v4; // x23
  int v5; // w8
  int v6; // w9
  __int64 driver_buf; // x0
  __int64 v8; // x21
  __int64 result; // x0
  __int64 *v10; // x20
  __int64 *v11; // x20
  __int64 v12; // x24
  __int64 v13; // x4
  __int64 *v14; // x8
  char v15; // w9
  unsigned int v16; // w5
  __int64 *v17; // x8
  __int64 v18; // x8
  __int64 v19; // x21
  __int64 v20; // x0
  __int64 v21; // x9
  __int64 v22; // x9

  v4 = a1 + 38436;
  v5 = *(_DWORD *)(a1 + 38708);
  if ( v5 )
  {
    v6 = *(_DWORD *)(a1 + 33416);
    *(_DWORD *)(a1 + 38708) = 0;
    ((void (__fastcall *)(__int64, __int64, _QWORD, const char *))msm_vidc_update_cap_value)(
      a1,
      173,
      v5 + v6,
      "msm_vdec_qbuf");
    msm_vidc_set_session_priority(a1, 0xADu);
  }
  if ( *(_BYTE *)(a1 + 3680) != 1 || *(_DWORD *)(a2 + 12) != 9 )
  {
    result = msm_vidc_queue_buffer_single(a1, a2);
    if ( (_DWORD)result )
      return result;
    goto LABEL_11;
  }
  if ( !*(_DWORD *)(a1 + 3684) )
  {
    if ( (msm_vidc_debug & 1) != 0 )
    {
      printk(&unk_83321, "err ", 0xFFFFFFFFLL, "codec", "msm_vdec_qbuf_batch");
      return 4294967274LL;
    }
    return 4294967274LL;
  }
  driver_buf = msm_vidc_get_driver_buf(a1, a2);
  if ( !driver_buf )
    return 4294967274LL;
  v8 = driver_buf;
  if ( (is_state(a1, 0) & 1) != 0 || (is_state(a1, 1) & 1) != 0 )
  {
    print_vidc_buffer(4, "low ", "qbuf deferred", a1, v8);
LABEL_11:
    if ( *(_DWORD *)(a2 + 12) == 9 )
    {
      if ( *(_BYTE *)(v4 + 256) == 1 )
      {
        v10 = *(__int64 **)(a1 + 2584);
        if ( v10 != (__int64 *)(a1 + 2584) )
        {
          while ( 1 )
          {
            if ( (v10[10] & 0x44) == 0x40 )
            {
              result = venus_hfi_release_buffer(a1, v10);
              if ( (_DWORD)result )
                return result;
              *((_DWORD *)v10 + 20) = v10[10] & 0xFFFFFFBB | 4;
              print_vidc_buffer(4, "low ", "release buf", a1, v10);
            }
            v10 = (__int64 *)*v10;
            if ( v10 == (__int64 *)(a1 + 2584) )
              return 0;
          }
        }
        return 0;
      }
      if ( *(_BYTE *)(v4 + 257) == 1 )
      {
        v11 = *(__int64 **)(a1 + 2584);
        v12 = a1 + 2584;
        if ( v11 != (__int64 *)(a1 + 2584) )
        {
          LODWORD(v13) = 0;
          v14 = *(__int64 **)(a1 + 2584);
          do
          {
            v15 = *((_DWORD *)v14 + 20);
            v14 = (__int64 *)*v14;
            if ( (v15 & 6) == 2 )
              v13 = (unsigned int)(v13 + 1);
            else
              v13 = (unsigned int)v13;
          }
          while ( v14 != (__int64 *)v12 );
          if ( (unsigned int)v13 >= 0x21 )
          {
            v16 = 0;
            v17 = *(__int64 **)(a1 + 2584);
            do
            {
              if ( (v17[10] & 6) == 2 )
              {
                v21 = v17[7];
                if ( (v21 != *(_DWORD *)v4 || *((_DWORD *)v17 + 11) != *(_DWORD *)(v4 + 12))
                  && (v21 != *(_DWORD *)(v4 + 16) || *((_DWORD *)v17 + 11) != *(_DWORD *)(v4 + 28))
                  && (v21 != *(_DWORD *)(v4 + 32) || *((_DWORD *)v17 + 11) != *(_DWORD *)(v4 + 44))
                  && (v21 != *(_DWORD *)(v4 + 48) || *((_DWORD *)v17 + 11) != *(_DWORD *)(v4 + 60))
                  && (v21 != *(_DWORD *)(v4 + 64) || *((_DWORD *)v17 + 11) != *(_DWORD *)(v4 + 76))
                  && (v21 != *(_DWORD *)(v4 + 80) || *((_DWORD *)v17 + 11) != *(_DWORD *)(v4 + 92))
                  && (v21 != *(_DWORD *)(v4 + 96) || *((_DWORD *)v17 + 11) != *(_DWORD *)(v4 + 108))
                  && (v21 != *(_DWORD *)(v4 + 112) || *((_DWORD *)v17 + 11) != *(_DWORD *)(v4 + 124))
                  && (v21 != *(_DWORD *)(v4 + 128) || *((_DWORD *)v17 + 11) != *(_DWORD *)(v4 + 140))
                  && (v21 != *(_DWORD *)(v4 + 144) || *((_DWORD *)v17 + 11) != *(_DWORD *)(v4 + 156))
                  && (v21 != *(_DWORD *)(v4 + 160) || *((_DWORD *)v17 + 11) != *(_DWORD *)(v4 + 172))
                  && (v21 != *(_DWORD *)(v4 + 176) || *((_DWORD *)v17 + 11) != *(_DWORD *)(v4 + 188))
                  && (v21 != *(_DWORD *)(v4 + 192) || *((_DWORD *)v17 + 11) != *(_DWORD *)(v4 + 204))
                  && (v21 != *(_DWORD *)(v4 + 208) || *((_DWORD *)v17 + 11) != *(_DWORD *)(v4 + 220))
                  && (v21 != *(_DWORD *)(v4 + 224) || *((_DWORD *)v17 + 11) != *(_DWORD *)(v4 + 236))
                  && (v21 != *(_DWORD *)(v4 + 240) || *((_DWORD *)v17 + 11) != *(_DWORD *)(v4 + 252)) )
                {
                  ++v16;
                }
              }
              v17 = (__int64 *)*v17;
            }
            while ( v17 != (__int64 *)v12 );
            if ( v16 > *(_DWORD *)(a1 + 2560) )
            {
              if ( a1 && (msm_vidc_debug & 4) != 0 )
              {
                printk(&unk_899EC, "low ", a1 + 340, "msm_vdec_release_nonref_buffers", v13);
                v11 = *(__int64 **)(a1 + 2584);
                if ( v11 != (__int64 *)v12 )
                  goto LABEL_87;
              }
              else if ( v11 != (__int64 *)v12 )
              {
                do
                {
LABEL_87:
                  if ( (v11[10] & 6) == 2 )
                  {
                    v22 = v11[7];
                    if ( (v22 != *(_DWORD *)v4 || *((_DWORD *)v11 + 11) != *(_DWORD *)(v4 + 12))
                      && (v22 != *(_DWORD *)(v4 + 16) || *((_DWORD *)v11 + 11) != *(_DWORD *)(v4 + 28))
                      && (v22 != *(_DWORD *)(v4 + 32) || *((_DWORD *)v11 + 11) != *(_DWORD *)(v4 + 44))
                      && (v22 != *(_DWORD *)(v4 + 48) || *((_DWORD *)v11 + 11) != *(_DWORD *)(v4 + 60))
                      && (v22 != *(_DWORD *)(v4 + 64) || *((_DWORD *)v11 + 11) != *(_DWORD *)(v4 + 76))
                      && (v22 != *(_DWORD *)(v4 + 80) || *((_DWORD *)v11 + 11) != *(_DWORD *)(v4 + 92))
                      && (v22 != *(_DWORD *)(v4 + 96) || *((_DWORD *)v11 + 11) != *(_DWORD *)(v4 + 108))
                      && (v22 != *(_DWORD *)(v4 + 112) || *((_DWORD *)v11 + 11) != *(_DWORD *)(v4 + 124))
                      && (v22 != *(_DWORD *)(v4 + 128) || *((_DWORD *)v11 + 11) != *(_DWORD *)(v4 + 140))
                      && (v22 != *(_DWORD *)(v4 + 144) || *((_DWORD *)v11 + 11) != *(_DWORD *)(v4 + 156))
                      && (v22 != *(_DWORD *)(v4 + 160) || *((_DWORD *)v11 + 11) != *(_DWORD *)(v4 + 172))
                      && (v22 != *(_DWORD *)(v4 + 176) || *((_DWORD *)v11 + 11) != *(_DWORD *)(v4 + 188))
                      && (v22 != *(_DWORD *)(v4 + 192) || *((_DWORD *)v11 + 11) != *(_DWORD *)(v4 + 204))
                      && (v22 != *(_DWORD *)(v4 + 208) || *((_DWORD *)v11 + 11) != *(_DWORD *)(v4 + 220))
                      && (v22 != *(_DWORD *)(v4 + 224) || *((_DWORD *)v11 + 11) != *(_DWORD *)(v4 + 236))
                      && (v22 != *(_DWORD *)(v4 + 240) || *((_DWORD *)v11 + 11) != *(_DWORD *)(v4 + 252)) )
                    {
                      *((_DWORD *)v11 + 20) |= 4u;
                      print_vidc_buffer(4, "low ", "release buf", a1, v11);
                      result = venus_hfi_release_buffer(a1, v11);
                      if ( (_DWORD)result )
                        break;
                    }
                  }
                  v11 = (__int64 *)*v11;
                  result = 0;
                }
                while ( v11 != (__int64 *)v12 );
                return result;
              }
            }
          }
        }
      }
    }
    return 0;
  }
  if ( *(_DWORD *)(a1 + 1916) >= 0x65u && (unsigned int)msm_vidc_num_buffers(a1, 2, 1) < *(_DWORD *)(a1 + 3684) )
  {
    print_vidc_buffer(4, "low ", "batch-qbuf deferred", a1, v8);
    if ( a1 && (v18 = *(_QWORD *)(a1 + 320)) != 0 )
    {
      v19 = *(_QWORD *)(v18 + 6224);
      v20 = _msecs_to_jiffies(*(unsigned int *)(v18 + 4496));
      mod_delayed_work_on(32, v19, a1 + 3688, v20);
    }
    else if ( (msm_vidc_debug & 1) != 0 )
    {
      printk(&unk_83321, "err ", 0xFFFFFFFFLL, "codec", "schedule_batch_work");
    }
    goto LABEL_11;
  }
  if ( a1 )
  {
    cancel_delayed_work(a1 + 3688);
  }
  else if ( (msm_vidc_debug & 1) != 0 )
  {
    printk(&unk_8E20F, "err ", 0xFFFFFFFFLL, "codec", "cancel_batch_work");
  }
  result = msm_vidc_queue_deferred_buffers(a1, 2);
  if ( !(_DWORD)result )
    goto LABEL_11;
  return result;
}
