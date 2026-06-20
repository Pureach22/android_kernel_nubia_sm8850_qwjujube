_QWORD *cam_sensor_module_debug_deregister()
{
  _QWORD *result; // x0

  result = (_QWORD *)display_buf;
  if ( display_buf )
  {
    if ( mem_trace_en == 1 )
      return cam_mem_trace_free((_QWORD *)display_buf, 0);
    else
      return (_QWORD *)kvfree(display_buf);
  }
  return result;
}
