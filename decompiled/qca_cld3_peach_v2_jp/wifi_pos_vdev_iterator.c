void __fastcall wifi_pos_vdev_iterator(__int64 a1, __int64 a2, __int64 a3)
{
  _BYTE *v3; // x11
  int v4; // w9

  v3 = (_BYTE *)(a3 + 2LL * (unsigned int)vdev_idx);
  v4 = vdev_idx + 1;
  *v3 = *(_DWORD *)(a2 + 16);
  v3[1] = *(_BYTE *)(a2 + 104);
  vdev_idx = v4;
}
