__int64 __fastcall mhi_driver_probe(__int64 a1)
{
  __int64 v1; // x22
  __int64 v2; // x23
  __int64 *v3; // x19
  __int64 v4; // x20
  __int64 v5; // x21
  __int64 result; // x0
  __int64 v7; // x8
  __int64 (__fastcall *v8)(__int64 *, __int64); // x8
  __int64 v9; // x1
  int v10; // w0
  unsigned int v11; // w20

  v1 = *(_QWORD *)(a1 - 24);
  v2 = *(_QWORD *)(a1 - 16);
  v3 = (__int64 *)(a1 - 40);
  v4 = *(_QWORD *)(a1 + 136);
  v5 = *(_QWORD *)(a1 - 8);
  result = mhi_device_get_sync(a1 - 40);
  if ( !(_DWORD)result )
  {
    if ( v2 )
    {
      if ( *(_BYTE *)(v2 + 392) == 1 && !*(_QWORD *)(v4 - 8) )
        goto LABEL_20;
      v7 = *(_QWORD *)(v4 - 24);
      if ( (*(_BYTE *)(v2 + 394) & 1) == 0 && !v7 )
        goto LABEL_20;
      *(_QWORD *)(v2 + 280) = v7;
    }
    if ( !v5 )
      goto LABEL_16;
    if ( (*(_BYTE *)(v5 + 392) != 1 || *(_QWORD *)(v4 - 8))
      && ((*(_BYTE *)(v5 + 394) & 1) != 0 || *(_QWORD *)(v4 - 16))
      && (*(_BYTE *)(*(_QWORD *)(v1 + 248) + 264LL * *(unsigned int *)(v5 + 204) + 257) != 1 || *(_QWORD *)(v4 - 8)) )
    {
      *(_QWORD *)(v5 + 280) = *(_QWORD *)(v4 - 16);
LABEL_16:
      v8 = *(__int64 (__fastcall **)(__int64 *, __int64))(v4 - 40);
      v9 = *v3;
      if ( *((_DWORD *)v8 - 1) != 289750335 )
        __break(0x8228u);
      v10 = v8(v3, v9);
      if ( !v10 )
      {
        v11 = 0;
LABEL_22:
        mhi_device_put(v3);
        return v11;
      }
LABEL_21:
      v11 = v10;
      mhi_unprepare_from_transfer(v3);
      goto LABEL_22;
    }
LABEL_20:
    v10 = -22;
    goto LABEL_21;
  }
  return result;
}
