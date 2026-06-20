__int64 __fastcall ocp_notifier_read_entry(_QWORD *a1, __int64 a2, unsigned int a3, __int64 a4)
{
  unsigned int v4; // w8
  unsigned __int64 v8; // x0
  __int64 v9; // x2
  unsigned int v10; // w19
  unsigned __int64 v11; // x19
  _QWORD v13[2]; // [xsp+0h] [xbp-10h] BYREF

  v13[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_DWORD *)(a2 + 8);
  v13[0] = 0;
  if ( v4 <= a3 )
    goto LABEL_7;
  v8 = nvmem_cell_read(*(_QWORD *)a2, v13);
  if ( v8 >= 0xFFFFFFFFFFFFF001LL )
  {
    v10 = v8;
    dev_err(*a1, "failed to read nvmem cell, ret=%d\n", v8);
    goto LABEL_8;
  }
  v9 = (int)(2 * a3);
  if ( v13[0] <= (v9 | 1uLL) )
  {
    v11 = v8;
    dev_err(*a1, "invalid OCP log index=%i\n", v9);
    kfree(v11);
LABEL_7:
    v10 = -22;
    goto LABEL_8;
  }
  *(_WORD *)a4 = *(unsigned __int8 *)(v8 + (v9 | 1)) | (((*(_BYTE *)(v8 + v9) >> 4) & 0xF) << 8);
  *(_BYTE *)(a4 + 2) = *(_BYTE *)(v8 + v9) & 7;
  kfree(v8);
  v10 = 0;
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return v10;
}
