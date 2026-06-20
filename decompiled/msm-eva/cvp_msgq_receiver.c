__int64 __fastcall cvp_msgq_receiver(unsigned __int64 a1)
{
  unsigned int v1; // w26
  __int64 v3; // x20
  unsigned int *v4; // x27
  _DWORD *v5; // x28
  unsigned __int64 StatusReg; // x23
  unsigned int v7; // w0
  __int64 v8; // x3
  int v9; // w5
  int v10; // w8
  __int64 v11; // x9
  __int64 v12; // x10
  __int64 v13; // x9
  __int64 v14; // x11
  __int64 v15; // x8
  __int64 v16; // x10
  unsigned int v17; // w12
  __int64 v18; // x8
  __int64 v19; // x9
  __int64 v20; // x8
  __int64 v21; // x8
  __int64 v22; // x8
  __int64 v23; // x9
  __int64 v24; // x10
  __int64 v25; // x8
  int v26; // w11
  __int64 v27; // x9
  __int64 v28; // x8
  __int64 v29; // x8
  __int64 v30; // x8
  int v31; // w9
  __int64 v32; // x8
  __int64 v33; // x11
  unsigned __int64 v34; // x21
  __int64 v35; // x22
  __int64 (__fastcall *v36)(_QWORD, _QWORD, _QWORD); // x0
  unsigned __int64 v38; // x8
  _QWORD v39[2]; // [xsp+0h] [xbp-10h] BYREF

  v1 = -22;
  v39[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || a1 > 0xFFFFFFFFFFFFF000LL )
    goto LABEL_43;
  v39[0] = 0;
  v3 = _kmalloc_cache_noprof(_kmalloc_cache_noprof, 3520, 80);
  if ( !v3 )
    goto LABEL_40;
  do
  {
    v4 = (unsigned int *)(a1 + 368);
    v5 = (_DWORD *)(a1 + 288);
    StatusReg = _ReadStatusReg(SP_EL0);
    while ( 1 )
    {
      while ( 1 )
      {
        while ( 1 )
        {
          while ( 1 )
          {
            v7 = gh_msgq_recv(*(_QWORD *)(a1 + 56), v3, 80, v39, 0);
            if ( !v7 )
              break;
            v1 = v7;
            if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
              printk(&unk_93848, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
            if ( v1 != -11 )
            {
              kfree(v3);
              goto LABEL_43;
            }
          }
          v9 = *(_DWORD *)v3;
          v10 = BYTE1(msm_cvp_debug) >> 7;
          if ( msm_cvp_debug_out )
            v10 = 0;
          if ( (v9 & 0x10000000) != 0 )
            break;
          if ( v10 )
          {
            printk(&unk_94131, &unk_85102, "cvp_msgq_receiver", v8);
            if ( !*v5 )
              goto LABEL_28;
LABEL_15:
            if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
              printk(&unk_89B2F, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
          }
          else
          {
            if ( *v5 )
              goto LABEL_15;
LABEL_28:
            v21 = *(_QWORD *)(v3 + 40);
            *(_QWORD *)(a1 + 320) = *(_QWORD *)(v3 + 32);
            *(_QWORD *)(a1 + 328) = v21;
            v22 = *(_QWORD *)(v3 + 24);
            *(_QWORD *)(a1 + 304) = *(_QWORD *)(v3 + 16);
            *(_QWORD *)(a1 + 312) = v22;
            v23 = *(_QWORD *)(v3 + 72);
            *(_QWORD *)(a1 + 352) = *(_QWORD *)(v3 + 64);
            *(_QWORD *)(a1 + 360) = v23;
            v24 = *(_QWORD *)(v3 + 56);
            *(_QWORD *)(a1 + 336) = *(_QWORD *)(v3 + 48);
            *(_QWORD *)(a1 + 344) = v24;
            v25 = *(_QWORD *)(v3 + 8);
            *(_QWORD *)v5 = *(_QWORD *)v3;
            *(_QWORD *)(a1 + 296) = v25;
            v26 = *(_DWORD *)(a1 + 296);
            *(_DWORD *)(a1 + 288) ^= 0x10000000u;
            v27 = *(_QWORD *)(a1 + 344);
            *(_QWORD *)(v3 + 48) = *(_QWORD *)(a1 + 336);
            *(_QWORD *)(v3 + 56) = v27;
            v28 = *(_QWORD *)(a1 + 360);
            *(_QWORD *)(v3 + 64) = *(_QWORD *)(a1 + 352);
            *(_QWORD *)(v3 + 72) = v28;
            v29 = *(_QWORD *)(a1 + 312);
            *(_QWORD *)(v3 + 16) = *(_QWORD *)(a1 + 304);
            *(_QWORD *)(v3 + 24) = v29;
            v30 = *(_QWORD *)(a1 + 328);
            v31 = 4 * v26;
            *(_QWORD *)(v3 + 32) = *(_QWORD *)(a1 + 320);
            *(_QWORD *)(v3 + 40) = v30;
            v33 = *(_QWORD *)v5;
            v32 = *(_QWORD *)(a1 + 296);
            v39[0] = (unsigned int)(v31 + 16);
            *(_QWORD *)v3 = v33;
            *(_QWORD *)(v3 + 8) = v32;
            if ( (unsigned int)(v31 + 16) < 0x51 )
            {
              if ( (gh_msgq_send(*(_QWORD *)(a1 + 56), v3, (unsigned int)(v31 + 16), 1) & 0x80000000) != 0
                && (msm_cvp_debug & 1) != 0
                && !msm_cvp_debug_out )
              {
                printk(&unk_93894, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
              }
              *v5 = 0;
            }
            else
            {
              if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
                printk(&unk_873C1, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
              *v5 = 0;
            }
          }
        }
        if ( v10 )
        {
          printk(&unk_9081A, &unk_85102, "cvp_msgq_receiver", v8);
          v9 = *(_DWORD *)v3;
        }
        if ( (v9 & 0x11) == *v4 && *v4 < 7 )
          break;
        if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
          printk(&unk_8FEC6, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      }
      v11 = *(_QWORD *)(v3 + 56);
      *(_QWORD *)(a1 + 416) = *(_QWORD *)(v3 + 48);
      *(_QWORD *)(a1 + 424) = v11;
      v12 = *(_QWORD *)(v3 + 72);
      v13 = *(_QWORD *)v3;
      v14 = *(_QWORD *)(v3 + 8);
      *(_QWORD *)(a1 + 432) = *(_QWORD *)(v3 + 64);
      *(_QWORD *)(a1 + 440) = v12;
      v15 = *(_QWORD *)(v3 + 16);
      v16 = *(_QWORD *)(v3 + 24);
      *(_QWORD *)v4 = v13;
      *(_QWORD *)(a1 + 376) = v14;
      v17 = *v4;
      *(_QWORD *)(a1 + 384) = v15;
      *(_QWORD *)(a1 + 392) = v16;
      v19 = *(_QWORD *)(v3 + 32);
      v18 = *(_QWORD *)(v3 + 40);
      *v4 = v17 & 0xEFFFFFFF;
      *(_QWORD *)(a1 + 400) = v19;
      *(_QWORD *)(a1 + 408) = v18;
      v20 = (v17 & 0xEFFFFFFF) - 1;
      if ( (unsigned int)v20 >= 7 )
        break;
      complete(a1 + 96 + 32 * v20);
    }
    __break(0x5512u);
    v34 = _ReadStatusReg(SP_EL0);
    v35 = *(_QWORD *)(v34 + 80);
    v36 = _kmalloc_cache_noprof;
    *(_QWORD *)(v34 + 80) = &cvp_msgq_receiver__alloc_tag;
    v3 = _kmalloc_cache_noprof(v36, 3520, 80);
    *(_QWORD *)(v34 + 80) = v35;
  }
  while ( v3 );
LABEL_40:
  v1 = -12;
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v38 = _ReadStatusReg(SP_EL0);
    printk(&unk_87F7B, *(unsigned int *)(v38 + 1800), *(unsigned int *)(v38 + 1804), &unk_8E7CE);
  }
LABEL_43:
  _ReadStatusReg(SP_EL0);
  return v1;
}
