__int64 __fastcall qcom_smem_alloc(unsigned int a1, unsigned int a2, __int64 a3)
{
  __int64 result; // x0
  __int64 v7; // x1
  __int64 v8; // x1
  __int64 v9; // t1
  unsigned int v10; // w19
  __int64 v11; // x8
  __int64 v12; // x9
  _DWORD *v13; // x9
  int v14; // t1
  unsigned __int64 v15; // x10
  int v16; // w9
  int v17; // w10
  _QWORD v18[2]; // [xsp+0h] [xbp-10h] BYREF

  v18[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !_smem )
  {
    result = 4294966779LL;
    goto LABEL_11;
  }
  v18[0] = 0;
  if ( a2 <= 7 )
  {
    dev_err(*(_QWORD *)_smem, "Rejecting allocation of static entry %d\n", a2);
    result = 4294967274LL;
    goto LABEL_11;
  }
  if ( *(_DWORD *)(_smem + 16) <= a2 )
  {
    __break(0x800u);
    result = 4294967274LL;
    goto LABEL_11;
  }
  result = _hwspin_lock_timeout(*(_QWORD *)(_smem + 8), 1000, 1, v18);
  if ( (_DWORD)result )
  {
LABEL_11:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  if ( a1 <= 0x18 && (v7 = _smem + 32LL * a1, v9 = *(_QWORD *)(v7 + 72), v8 = v7 + 72, v9)
    || (v8 = _smem + 40, *(_QWORD *)(_smem + 40)) )
  {
    v10 = qcom_smem_alloc_private(_smem, v8, a2, a3);
LABEL_9:
    _hwspin_unlock(*(_QWORD *)(_smem + 8), 1, v18);
    result = v10;
    goto LABEL_11;
  }
  if ( a2 < 0x201 )
  {
    v11 = *(_QWORD *)(_smem + 888);
    v12 = v11 + 16LL * a2;
    v14 = *(_DWORD *)(v12 + 208);
    v13 = (_DWORD *)(v12 + 208);
    if ( v14 )
    {
      v10 = -17;
    }
    else
    {
      v15 = (a3 + 7) & 0xFFFFFFFFFFFFFFF8LL;
      if ( v15 > *(unsigned int *)(v11 + 200) )
      {
        __break(0x800u);
        v10 = -12;
      }
      else
      {
        v10 = 0;
        v13[1] = *(_DWORD *)(v11 + 196);
        v13[2] = v15;
        __dsb(0xEu);
        *v13 = 1;
        v16 = *(_DWORD *)(v11 + 196) + v15;
        v17 = *(_DWORD *)(v11 + 200) - v15;
        *(_DWORD *)(v11 + 196) = v16;
        *(_DWORD *)(v11 + 200) = v17;
      }
    }
    goto LABEL_9;
  }
  __break(0x5512u);
  return ((__int64 (*)(void))qcom_smem_alloc_private)();
}
