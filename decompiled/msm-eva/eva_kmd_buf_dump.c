__int64 __fastcall eva_kmd_buf_dump(__int64 result, __int64 a2, int a3)
{
  __int64 v3; // x19
  __int64 *v4; // x8
  __int64 v5; // x20
  __int64 v6; // x23
  __int64 v9; // x8
  _DWORD *v10; // x9
  int v11; // w8
  int v12; // w8
  unsigned __int64 v13; // x11
  _QWORD *v14; // x10
  __int64 v15; // x11
  unsigned int v16; // w9
  int v17; // w8
  unsigned __int64 v18; // x8
  unsigned __int64 StatusReg; // x8

  v3 = *(_QWORD *)(cvp_driver + 48);
  if ( v3 && (v4 = *(__int64 **)(v3 + 256)) != nullptr && (v5 = *v4) != 0 )
  {
    v6 = result;
    mutex_lock(v3 + 1320);
    v9 = *(unsigned int *)(v3 + 1368);
    if ( (unsigned int)v9 >= 0x101 )
    {
      __break(0x5512u);
      JUMPOUT(0x60B80);
    }
    v10 = (_DWORD *)(v3 + 16 * v9);
    v11 = *(_DWORD *)(v6 + 324) ^ *(_DWORD *)(v6 + 320);
    v10[347] = a3;
    v10[346] = v11;
    v12 = *(_DWORD *)(v3 + 1312);
    v10[348] = *(_DWORD *)(a2 + 64);
    v10[349] = *(_DWORD *)(a2 + 80);
    v13 = *(_QWORD *)(v5 + 2528);
    v14 = (_QWORD *)(v13 + (unsigned int)(4 * v12));
    if ( (unsigned __int64)v14 < v13 || (unsigned __int64)v14 > v13 + 0x80000 )
    {
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        StatusReg = _ReadStatusReg(SP_EL0);
        printk(&unk_9405F, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      }
    }
    else
    {
      v15 = *((_QWORD *)v10 + 174);
      *v14 = *((_QWORD *)v10 + 173);
      v14[1] = v15;
      v16 = *(_DWORD *)(v3 + 1368) + 1;
      *(_DWORD *)(v3 + 1368) = v16;
      if ( v16 < 0x100 )
      {
        v17 = v12 + 4;
      }
      else
      {
        v17 = 0;
        *(_DWORD *)(v3 + 1368) = 0;
      }
      *(_DWORD *)(v3 + 1312) = v17;
    }
    return mutex_unlock(v3 + 1320);
  }
  else if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v18 = _ReadStatusReg(SP_EL0);
    return printk(&unk_8C2C4, *(unsigned int *)(v18 + 1800), *(unsigned int *)(v18 + 1804), &unk_8E7CE);
  }
  return result;
}
