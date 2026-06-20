__int64 __fastcall msm_property_pop_dirty(__int64 a1, __int64 a2)
{
  _QWORD *v3; // x9
  _QWORD *v4; // x10
  __int64 v5; // x11
  __int64 v6; // x8
  unsigned __int64 v7; // x19

  if ( a1 && a2 && *(_QWORD *)(a2 + 8) )
  {
    if ( (mutex_is_locked(a1 + 80) & 1) == 0 )
      __break(0x800u);
    v3 = *(_QWORD **)(a2 + 16);
    if ( v3 == (_QWORD *)(a2 + 16) )
    {
      LODWORD(v7) = -11;
    }
    else
    {
      v4 = (_QWORD *)v3[1];
      if ( (_QWORD *)*v4 == v3 && (v5 = *v3, *(_QWORD **)(*v3 + 8LL) == v3) )
      {
        v6 = a2;
        *(_QWORD *)(v5 + 8) = v4;
        *v4 = v5;
      }
      else
      {
        _list_del_entry_valid_or_report(*(_QWORD *)(a2 + 16));
        v6 = a2;
      }
      *v3 = v3;
      v3[1] = v3;
      v7 = ((unsigned __int64)v3 - *(_QWORD *)(v6 + 8) - 16) >> 5;
      _drm_dev_dbg(0, 0, 2, "property %d dirty\n", v7);
    }
  }
  else
  {
    _drm_err("invalid argument(s)\n");
    LODWORD(v7) = -22;
  }
  return (unsigned int)v7;
}
