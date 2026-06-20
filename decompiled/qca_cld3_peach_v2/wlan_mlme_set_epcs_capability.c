__int64 __fastcall wlan_mlme_set_epcs_capability(__int64 a1, char a2)
{
  __int64 psoc_ext_obj_fl; // x20
  __int64 result; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x22
  _QWORD *v14; // x10
  _QWORD *v15; // x9
  unsigned __int64 *v16; // x8
  __int64 v17; // x11
  unsigned __int64 v18; // x11
  unsigned __int64 v19; // x9
  unsigned __int64 v20; // x11

  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  result = _cds_get_context(53, "wlan_mlme_set_epcs_capability");
  if ( psoc_ext_obj_fl && result )
  {
    v13 = result + 20480;
    result = qdf_trace_msg(
               0x68u,
               8u,
               "%s: set mlme epcs capability from %d to %d",
               v5,
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               "wlan_mlme_set_epcs_capability",
               *(unsigned __int8 *)(psoc_ext_obj_fl + 3598),
               a2 & 1);
    v14 = (_QWORD *)(psoc_ext_obj_fl + 1501);
    v15 = (_QWORD *)(v13 + 1585);
    v16 = (unsigned __int64 *)(v13 + 1677);
    v17 = *(_QWORD *)(psoc_ext_obj_fl + 1501);
    *(_BYTE *)(psoc_ext_obj_fl + 3598) = a2 & 1;
    if ( (a2 & 1) != 0 )
    {
      *v14 = v17 | 1;
      v18 = *v16;
      *v15 |= 1uLL;
      v19 = v18 | 1;
    }
    else
    {
      *v14 = v17 & 0xFFFFFFFFFFFFFFFELL;
      v20 = *v16;
      *v15 &= ~1uLL;
      v19 = v20 & 0xFFFFFFFFFFFFFFFELL;
    }
    *v16 = v19;
  }
  return result;
}
