__int64 __fastcall qdf_get_keyed_hash(
        const char *a1,
        __int64 a2,
        unsigned int a3,
        _QWORD *a4,
        unsigned int *a5,
        __int64 a6,
        __int64 a7)
{
  unsigned __int64 v14; // x0
  unsigned __int64 v15; // x19
  __int64 result; // x0
  unsigned int v17; // w0
  unsigned int v18; // w21
  char v19; // w8
  __int64 (__fastcall *v20)(_QWORD); // x8
  int v21; // w0
  const char *v22; // x2
  unsigned int v23; // t1
  _QWORD v24[48]; // [xsp+0h] [xbp-180h] BYREF

  v24[47] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = crypto_alloc_shash(a1, 0, 128);
  v15 = v14;
  if ( v14 < 0xFFFFFFFFFFFFF001LL )
  {
    if ( a2 && a3 && (v17 = crypto_shash_setkey(v14, a2, a3)) != 0 )
    {
      v18 = v17;
      qdf_trace_msg(56, 2, "%s: Set key failed for %s, ret:%d", "qdf_get_keyed_hash", a1, -v17);
    }
    else
    {
      memset(&v24[1], 0, 0x170u);
      v19 = *(_BYTE *)(v15 + 12);
      v24[0] = v15;
      if ( (v19 & 1) != 0 )
      {
        v22 = "%s: Failed to init hash for %s, ret:%d";
        v21 = -126;
      }
      else
      {
        v20 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v15 + 32) - 112LL);
        if ( *((_DWORD *)v20 - 1) != 1272602849 )
          __break(0x8228u);
        v21 = v20(v24);
        if ( v21 )
        {
          v22 = "%s: Failed to init hash for %s, ret:%d";
        }
        else if ( a6 )
        {
          while ( 1 )
          {
            v23 = *a5;
            a5 += 2;
            v21 = crypto_shash_update(v24, *a4, v23);
            if ( v21 )
              break;
            --a6;
            ++a4;
            if ( !a6 )
              goto LABEL_19;
          }
          v22 = "%s: Failed to update hash for %s, ret:%d";
        }
        else
        {
LABEL_19:
          v21 = crypto_shash_final(v24, a7);
          if ( !v21 )
          {
            v18 = 0;
            goto LABEL_14;
          }
          v22 = "%s: Failed to get digest for %s, ret:%d";
        }
      }
      v18 = v21;
      qdf_trace_msg(56, 2, v22, "qdf_get_keyed_hash", a1, (unsigned int)-v21);
    }
LABEL_14:
    crypto_destroy_tfm(v15, v15 + 8);
    result = v18;
    goto LABEL_15;
  }
  qdf_trace_msg(56, 2, "%s: Failed to allocate transformation for %s: %ld", "qdf_get_keyed_hash", a1, v14);
  result = 4294967274LL;
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
