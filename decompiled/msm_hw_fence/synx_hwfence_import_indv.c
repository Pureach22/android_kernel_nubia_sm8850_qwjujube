__int64 __fastcall synx_hwfence_import_indv(unsigned __int64 a1, unsigned __int64 a2)
{
  __int64 v2; // x30
  __int64 v3; // x4
  unsigned int *v4; // x8
  __int64 (__fastcall *v5)(_QWORD); // x9
  unsigned int v6; // w19
  __int64 v7; // x20
  unsigned __int64 fence; // x0
  __int64 result; // x0
  __int64 v13; // x19
  __int64 v14; // x30
  unsigned int v15; // w19
  __int64 v16; // x8
  unsigned int v18; // w19
  int v24; // w9
  unsigned int v25; // w19
  __int64 v26; // [xsp+10h] [xbp-20h] BYREF
  __int64 v27; // [xsp+18h] [xbp-18h]
  unsigned __int64 v28; // [xsp+20h] [xbp-10h]
  __int64 v29; // [xsp+28h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1
    || a1 > 0xFFFFFFFFFFFFF000LL
    || !a2
    || a2 > 0xFFFFFFFFFFFFF000LL
    || !*(_QWORD *)a2
    || *(_QWORD *)a2 > 0xFFFFFFFFFFFFF000LL
    || (v3 = *(unsigned int *)(a2 + 8), (v3 & 0xC) == 0) )
  {
    printk(&unk_222C0, "synx_hwfence_import_indv", 627, v2, a1);
    goto LABEL_28;
  }
  v4 = *(unsigned int **)(a2 + 16);
  if ( v4 )
  {
    if ( (v3 & 8) == 0 )
    {
      if ( (v3 & 4) != 0 )
      {
        v27 = 0;
        v28 = 0;
        v5 = (__int64 (__fastcall *)(_QWORD))off_2B780;
        v26 = 0;
        if ( off_2B780 )
        {
          v6 = *v4;
          v7 = v2;
          if ( (*v4 & 0x80000000) != 0 )
          {
            fence = hw_fence_interop_get_fence(v6);
          }
          else
          {
            if ( *((_DWORD *)off_2B780 - 1) != -1029165163 )
              __break(0x8229u);
            fence = v5(v6);
          }
          v28 = fence;
          if ( fence && fence < 0xFFFFFFFFFFFFF001LL )
          {
            v16 = *(_QWORD *)a2;
            LODWORD(v27) = 8;
            v26 = v16;
            result = synx_hwfence_import_fence(a1, &v26);
            if ( v28 )
            {
              _X8 = (unsigned int *)(v28 + 56);
              __asm { PRFM            #0x11, [X8] }
              do
                v24 = __ldxr(_X8);
              while ( __stlxr(v24 - 1, _X8) );
              if ( v24 == 1 )
              {
                __dmb(9u);
                v18 = result;
                dma_fence_release(_X8);
                result = v18;
              }
              else if ( v24 <= 0 )
              {
                v25 = result;
                refcount_warn_saturate(_X8, 3);
                result = v25;
              }
            }
            goto LABEL_29;
          }
          printk(&unk_29499, "synx_hwfence_import_handle", 605, v7, v6);
        }
        else
        {
          printk(&unk_268DA, "synx_hwfence_import_handle", 595, v2, 0);
        }
LABEL_28:
        result = 4294967274LL;
        goto LABEL_29;
      }
LABEL_30:
      printk(&unk_2B6D6, "synx_hwfence_import_indv", 644, v2, v3);
      goto LABEL_28;
    }
LABEL_18:
    result = ((__int64 (*)(void))synx_hwfence_import_fence)();
    goto LABEL_29;
  }
  if ( (v3 & 4) == 0 )
  {
    if ( (v3 & 8) == 0 )
      goto LABEL_30;
    goto LABEL_18;
  }
  v13 = v2;
  result = synx_hwfence_create_helper();
  if ( (_DWORD)result )
  {
    v14 = v13;
    v15 = result;
    printk(&unk_28A60, "synx_hwfence_import_indv", 635, v14, *(unsigned int *)(a2 + 8));
    result = v15;
  }
LABEL_29:
  _ReadStatusReg(SP_EL0);
  return result;
}
