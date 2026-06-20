__int64 __fastcall msm_vidc_allow_decode_batch(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v6; // x21
  int v7; // w22
  _QWORD *v8; // x9
  void *v9; // x0
  __int64 result; // x0
  const char *v11; // x4
  __int64 v12; // x2
  unsigned int v13; // w19
  unsigned int v14; // w8
  unsigned int v15; // w9
  __int64 v16; // x4
  unsigned int mbs_per_frame; // w0
  __int64 v18; // x5
  bool v19; // cc
  void *v20; // x0
  __int64 v21; // x2

  if ( (*(_BYTE *)(a1 + 3680) & 1) != 0 )
  {
    v6 = *(_QWORD *)(a1 + 320);
    if ( *(_QWORD *)(v6 + 4480) )
    {
      mutex_lock(v6 + 3856);
      v7 = 2;
      v8 = (_QWORD *)(v6 + 3528);
      do
      {
        v8 = (_QWORD *)*v8;
        --v7;
      }
      while ( v8 != (_QWORD *)(v6 + 3528) );
      mutex_unlock(v6 + 3856);
      if ( v7 )
      {
        if ( a1 )
        {
          if ( (msm_vidc_debug & 2) != 0 )
          {
            v9 = &unk_8122C;
LABEL_23:
            printk(v9, "high", a1 + 340, "msm_vidc_allow_decode_batch", a5);
            goto LABEL_24;
          }
          goto LABEL_24;
        }
      }
      else if ( *(_DWORD *)(a1 + 308) == 2 )
      {
        if ( *(_QWORD *)(a1 + 32576) )
        {
          if ( a1 )
          {
            if ( (msm_vidc_debug & 2) != 0 )
            {
              v9 = &unk_8FE78;
              goto LABEL_23;
            }
            goto LABEL_24;
          }
        }
        else if ( *(_DWORD *)(a1 + 312) == 8 )
        {
          if ( a1 )
          {
            if ( (msm_vidc_debug & 2) == 0 )
              goto LABEL_24;
            v9 = &unk_82B85;
            goto LABEL_23;
          }
        }
        else if ( *(_QWORD *)(a1 + 33416) )
        {
          if ( a1 )
          {
            if ( (msm_vidc_debug & 2) == 0 )
              goto LABEL_24;
            v9 = &unk_97942;
            goto LABEL_23;
          }
        }
        else
        {
          if ( !*(_QWORD *)(a1 + 15608) )
          {
            v14 = *(_DWORD *)(a1 + 19474);
            v15 = *(_DWORD *)(a1 + 19642);
            if ( v15 <= v14 )
              v16 = v14;
            else
              v16 = v15;
            if ( *(_QWORD *)(a1 + 18968) <= v16 )
            {
              if ( !a1 )
                return 0;
              if ( (msm_vidc_debug & 2) == 0 )
                goto LABEL_24;
              v20 = &unk_92FFF;
              v21 = a1 + 340;
            }
            else
            {
              mbs_per_frame = msm_vidc_get_mbs_per_frame((_DWORD *)a1);
              v18 = *(_QWORD *)(a1 + 18800);
              v16 = mbs_per_frame;
              v19 = v18 <= mbs_per_frame;
              result = v18 > mbs_per_frame;
              if ( !a1 || !v19 )
              {
                if ( !a1 )
                  return result;
                goto LABEL_25;
              }
              if ( (msm_vidc_debug & 2) == 0 )
                goto LABEL_24;
              v20 = &unk_8D887;
              v21 = a1 + 340;
            }
            printk(v20, "high", v21, "msm_vidc_allow_decode_batch", v16);
            goto LABEL_24;
          }
          if ( a1 )
          {
            if ( (msm_vidc_debug & 2) == 0 )
              goto LABEL_24;
            v9 = &unk_7F995;
            goto LABEL_23;
          }
        }
      }
      else if ( a1 )
      {
        if ( (msm_vidc_debug & 2) != 0 )
        {
          v9 = &unk_81260;
          goto LABEL_23;
        }
        goto LABEL_24;
      }
    }
    else if ( a1 )
    {
      if ( (msm_vidc_debug & 2) != 0 )
      {
        v9 = &unk_84DE2;
        goto LABEL_23;
      }
      goto LABEL_24;
    }
    return 0;
  }
  if ( !a1 )
    return 0;
  if ( (msm_vidc_debug & 2) != 0 )
  {
    v9 = &unk_88FCE;
    goto LABEL_23;
  }
LABEL_24:
  result = 0;
LABEL_25:
  if ( (msm_vidc_debug & 0xA) != 0 )
  {
    if ( (_DWORD)result )
      v11 = "enabled";
    else
      v11 = "disabled";
    v12 = a1 + 340;
    v13 = result;
    printk(&unk_9169A, "high", v12, "msm_vidc_allow_decode_batch", v11);
    return v13;
  }
  return result;
}
