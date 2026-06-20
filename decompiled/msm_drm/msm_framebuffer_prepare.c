__int64 __fastcall msm_framebuffer_prepare(__int64 a1, __int64 a2)
{
  const void *v2; // x30
  __int64 v3; // x8
  int v5; // w22
  unsigned int iova; // w21
  __int64 result; // x0
  unsigned int v9; // w21
  unsigned int v10; // w21
  int v11; // w0
  int v12; // w4
  unsigned int v13; // w19
  _QWORD v14[2]; // [xsp+0h] [xbp-10h] BYREF

  v14[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14[0] = 0;
  if ( !a1 )
  {
    _drm_err("from:%pS null fb\n", v2);
    result = 4294967274LL;
    goto LABEL_7;
  }
  v3 = *(_QWORD *)(a1 + 72);
  v5 = *(unsigned __int8 *)(v3 + 5);
  if ( !*(_BYTE *)(v3 + 5) )
    goto LABEL_5;
  iova = msm_gem_get_iova(*(_QWORD *)(a1 + 160), a2, v14);
  _drm_dev_dbg(0, 0, 1, "FB[%u]: iova[%d]: %08llx (%d)\n", *(_DWORD *)(a1 + 24), 0, v14[0], iova);
  result = iova;
  if ( !iova )
  {
    if ( v5 != 1 )
    {
      v9 = msm_gem_get_iova(*(_QWORD *)(a1 + 168), a2, v14);
      _drm_dev_dbg(0, 0, 1, "FB[%u]: iova[%d]: %08llx (%d)\n", *(_DWORD *)(a1 + 24), 1, v14[0], v9);
      result = v9;
      if ( v9 )
        goto LABEL_7;
      if ( v5 != 2 )
      {
        v10 = msm_gem_get_iova(*(_QWORD *)(a1 + 176), a2, v14);
        _drm_dev_dbg(0, 0, 1, "FB[%u]: iova[%d]: %08llx (%d)\n", *(_DWORD *)(a1 + 24), 2, v14[0], v10);
        result = v10;
        if ( v10 )
          goto LABEL_7;
        if ( v5 != 3 )
        {
          v11 = msm_gem_get_iova(*(_QWORD *)(a1 + 184), a2, v14);
          v12 = *(_DWORD *)(a1 + 24);
          v13 = v11;
          _drm_dev_dbg(0, 0, 1, "FB[%u]: iova[%d]: %08llx (%d)\n", v12, 3, v14[0], v11);
          result = v13;
          if ( v13 )
            goto LABEL_7;
          if ( v5 != 4 )
            __break(0x5512u);
        }
      }
    }
LABEL_5:
    result = 0;
  }
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
