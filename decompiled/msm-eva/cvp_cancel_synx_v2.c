__int64 __fastcall cvp_cancel_synx_v2(__int64 a1, int a2, __int64 a3, unsigned int a4)
{
  __int64 v4; // x21
  unsigned int v6; // w8
  __int64 v7; // x9
  signed int v8; // w9
  unsigned int v9; // w25
  __int64 result; // x0
  __int64 v11; // x26
  __int64 v12; // x22
  __int64 v13; // x27
  unsigned int v14; // w28
  unsigned int v15; // w20
  unsigned int v16; // w20
  unsigned __int64 v17; // x8
  unsigned __int64 StatusReg; // [xsp+0h] [xbp-10h]

  v4 = *(_QWORD *)(a1 + 15264);
  if ( a2 == 1 )
  {
    v6 = 0;
    v7 = 36;
    goto LABEL_5;
  }
  if ( a2 == 2 )
  {
    v6 = *(_DWORD *)(a3 + 36);
    v7 = 32;
LABEL_5:
    v8 = *(_DWORD *)(a3 + v7);
    v9 = v8 - v6;
    if ( v8 <= (int)v6 )
      return 0;
    result = 0;
    v11 = a3 + 44;
    v12 = v6;
    if ( v6 <= 0x40 )
      v13 = 64;
    else
      v13 = v6;
    StatusReg = _ReadStatusReg(SP_EL0);
    while ( 1 )
    {
      if ( v13 == v12 )
      {
        __break(0x5512u);
        return cvp_dump_fence_queue_v2(result);
      }
      v14 = *(_DWORD *)(v11 + 4 * v12);
      if ( v14 )
      {
        result = synx_signal(v4, v14, a4);
        if ( (msm_cvp_debug & 0x80) != 0 && !msm_cvp_debug_out )
        {
          v16 = result;
          printk(&unk_8FD22, "synx", v14, a1);
          result = v16;
          if ( v16 )
          {
LABEL_16:
            if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
            {
              v15 = result;
              printk(&unk_940AF, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
              result = v15;
            }
          }
        }
        else if ( (_DWORD)result )
        {
          goto LABEL_16;
        }
      }
      --v9;
      ++v12;
      if ( !v9 )
        return result;
    }
  }
  result = 4294967274LL;
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v17 = _ReadStatusReg(SP_EL0);
    printk(&unk_8B8CB, *(unsigned int *)(v17 + 1800), *(unsigned int *)(v17 + 1804), &unk_8E7CE);
    return 4294967274LL;
  }
  return result;
}
