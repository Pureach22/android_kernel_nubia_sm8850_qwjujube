__int64 __fastcall stm_output_free(__int64 a1, _DWORD *a2)
{
  unsigned int v4; // w8
  __int64 v5; // x11
  unsigned int v6; // w10
  unsigned int v7; // w9
  bool v8; // cf
  unsigned int v9; // w9
  _DWORD *v10; // x21
  __int64 v11; // x8
  void (__fastcall *v12)(_QWORD); // x8

  raw_spin_lock(a1 + 1080);
  raw_spin_lock(a2);
  v4 = a2[3];
  if ( v4 )
  {
    v5 = *(_QWORD *)(a1 + 984);
    v6 = a2[1];
    v7 = *(_DWORD *)(v5 + 16);
    v8 = v6 >= v7;
    v9 = v6 - v7;
    if ( v8 && *(_DWORD *)(v5 + 20) >= v6 )
      v10 = *(_DWORD **)(a1 + 8LL * v9 + 1088);
    else
      v10 = nullptr;
    _bitmap_clear(v10 + 2, (unsigned int)a2[2], (unsigned int)(1 << (__clz(v4) ^ 0x1F)));
    *v10 += a2[3];
    a2[3] = 0;
  }
  v11 = *(_QWORD *)(a1 + 1064);
  if ( v11 )
  {
    v12 = *(void (__fastcall **)(_QWORD))(v11 + 40);
    if ( v12 )
    {
      if ( *((_DWORD *)v12 - 1) != -1788668684 )
        __break(0x8228u);
      v12(a2);
    }
  }
  raw_spin_unlock(a2);
  return raw_spin_unlock(a1 + 1080);
}
