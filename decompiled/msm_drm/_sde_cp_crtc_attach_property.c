__int64 __fastcall sde_cp_crtc_attach_property(__int64 *a1)
{
  __int64 v1; // x20
  __int64 v3; // x8
  __int64 v4; // x8
  __int64 v5; // x2
  __int64 v6; // x8
  __int64 *v7; // x1
  __int64 result; // x0

  v1 = *a1;
  drm_object_attach_property(*a1 + 112, a1[1], a1[4]);
  v3 = a1[2];
  *(_QWORD *)(v3 + 56) = v3 + 56;
  *(_QWORD *)(v3 + 64) = v3 + 56;
  v4 = a1[2];
  *(_QWORD *)(v4 + 72) = v4 + 72;
  *(_QWORD *)(v4 + 80) = v4 + 72;
  *(_DWORD *)a1[2] = *(_DWORD *)(a1[1] + 16);
  *(_DWORD *)(a1[2] + 4) = *(_DWORD *)(a1[1] + 48);
  LODWORD(v4) = *((_DWORD *)a1 + 6);
  *(_DWORD *)(a1[2] + 8) = v4;
  *(_BYTE *)(a1[2] + 88) = (unsigned int)v4 < 0x32;
  v5 = *(_QWORD *)(v1 + 4520);
  v6 = a1[2];
  v7 = (__int64 *)(v1 + 4520);
  result = v6 + 40;
  if ( *(_QWORD *)(v5 + 8) != v1 + 4520 || (__int64 *)result == v7 || v5 == result )
    return _list_add_valid_or_report(result, v7);
  *(_QWORD *)(v5 + 8) = result;
  *(_QWORD *)(v6 + 40) = v5;
  *(_QWORD *)(v6 + 48) = v7;
  *v7 = result;
  return result;
}
