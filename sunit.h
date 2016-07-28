/*
 * Copyright (C) 2016  Shan Ting <vxst@vxst.org>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

namespace sunit{
	void test_start(const char* unit_name);
	void test_start_with_log(const char* unit_name, const char* log_name);
	void test_end();

	void test(const char* component_name, bool condition);
	void test_fequal(const char* component_name, double a, double b);
	void test_likely(const char* component_name, double probability, bool condition);
}
