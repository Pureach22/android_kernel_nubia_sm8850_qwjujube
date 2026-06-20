__int64 __fastcall fill_alloc_response(__int64 result, unsigned int a2, _DWORD *a3)
{
  unsigned __int64 v3; // x27
  __int64 *v4; // x8
  int v5; // w10

  *(_BYTE *)(result + 4) = 1;
  if ( a2 >= 0xA )
  {
    __break(0x5512u);
  }
  else if ( ((96LL * a2) | 8uLL) <= 0x3C0 )
  {
    v4 = &memblock[12 * a2];
    v5 = *((_DWORD *)v4 + 2);
    *(_BYTE *)(result + 12) = 1;
    *(_DWORD *)(result + 16) = 1;
    *(_DWORD *)(result + 8) = v5;
    *(_QWORD *)(result + 24) = v4[9];
    *(_DWORD *)(result + 32) = *((_DWORD *)v4 + 14);
    LOWORD(v4) = *a3 != 0;
    *(_WORD *)result = (_WORD)v4;
    *(_WORD *)(result + 2) = 2 * (_WORD)v4;
    return result;
  }
  __break(1u);
  _WriteStatusReg(ARM64_SYSREG(3, 2, 7, 10, 1), v3);
  return modem_notifier_cb();
}
